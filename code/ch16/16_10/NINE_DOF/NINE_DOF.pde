
#include <Wire.h>
#include <AHRS.h>

const int accelerometer_address = 0x53;
const int magnetometer_address = 0x1E;
const int gyro_address = 0x68; //(if logic is low)

float accelVals[3], magVals[3], gyroVals[3];

// start GYRO
const float GYRO_SENSITIVITY = 14.375;
const byte INTCFG_ITG_RDY_EN = 0x04;  // 00000100
const byte INTCFG_RAW_RDY_EN = 0x01;  // 00000001
const byte PWRMGM_CLK_SEL = 0x07;  // 00000111
const byte BW256_SR8 = 0;
const byte RANGE2000 = 3;   // default
const byte NOSRDIVIDER = 0; 
const byte PLL_XGYRO_REF = 1;
const byte INT_STATUS  =  0x1A;  // R	Interrupt: Status
const byte GYRO_XOUT   =  0x1D ; // R	SENSOR: Gyro X 2bytes  
const byte DLPF_FS = 0x16;
const byte INT_CFG = 0x17;
const byte DLPFFS_FS_SEL = 0x18;
const byte DLPFFS_DLPF_CFG = 0x07;
const byte PWR_MGM = 0x3E;  // Power Management
// end GYRO

// start MAGNET
float gyroOffsets[3];
float magx_scale, magy_scale, magz_scale, magx_max, magy_max, magz_max;
// HMC5883 register map. For details see HMC5883 datasheet
const byte HMC5883_ADDR = 0x1E; // 7 bit address of the HMC5883 used with the Wire library
const byte HMC_POS_BIAS = 1;
const byte HMC_NEG_BIAS = 2;
const byte HMC5883_R_XM = 3; // reading from the magnetometer
const byte HMC5883_R_CONFA = 0;
const byte HMC5883_R_CONFB = 1;
const byte HMC5883_R_MODE = 2;
// end MAGNET

// ACCEL
const byte ACCEL_REG=0x32;

AHRS ahrs;

byte buffer[6];

void readmem(uint8_t dev_address, uint8_t _addr, uint8_t _nbytes, uint8_t _buff[]) {

  Wire.beginTransmission(dev_address); // start transmission to device 
  Wire.send(_addr); // sends register address to read from
  Wire.endTransmission(); // end transmission

    Wire.beginTransmission(dev_address); // start transmission to device 
  Wire.requestFrom(dev_address, _nbytes);// send data n-bytes read
  uint8_t i = 0; 
  while (Wire.available()) {
    _buff[i] = Wire.receive(); // receive DATA
    i++;
  }
  Wire.endTransmission(); // end transmission
}

void writemem(uint8_t dev_address, uint8_t _addr, uint8_t _val) {
  Wire.beginTransmission(dev_address);   // start transmission to device 
  Wire.send(_addr); // send register address
  Wire.send(_val); // send value to writemem
  Serial.print(Wire.endTransmission()); // end transmission
}


void initGyro()
{
  Serial.print(" init ITG ");
  uint8_t buff;

  // fs range
  readmem(gyro_address, DLPF_FS, 1, &buff);   
  writemem(gyro_address, DLPF_FS, ((buff & ~DLPFFS_FS_SEL) | (3 << 3)) ); 
  // filter
  readmem(gyro_address, DLPF_FS, 1, &buff);
  writemem(gyro_address, DLPF_FS, ((buff & ~DLPFFS_DLPF_CFG) | BW256_SR8)); 
  //clock
  readmem(gyro_address, PWR_MGM, 1, &buff);
  writemem(gyro_address, PWR_MGM, ((buff & ~PWRMGM_CLK_SEL) | PLL_XGYRO_REF)); 
  //itg ready
  readmem(gyro_address, INT_CFG, 1, &buff);
  writemem(gyro_address, INT_CFG, ((buff & ~INTCFG_ITG_RDY_EN) | 1 << 2)); 
  //raw ready
  readmem(gyro_address, INT_CFG, 1, &buff);
  writemem(gyro_address, INT_CFG, ((buff & ~INTCFG_RAW_RDY_EN) | 1)); 
  //delay
  delay(70); // time to delay

  zeroCalibrate(2500, 2);

}

void initMag()
{
  Serial.print(" init mag ");
  writemem(magnetometer_address, HMC5883_R_CONFA, 0x70);
  writemem(magnetometer_address, HMC5883_R_CONFB, 0xA0);
  writemem(magnetometer_address, HMC5883_R_MODE, 0x00);

}

void calibrateMag(unsigned char gain) {
  Serial.print(" calibrate mag ");
  magx_scale=1; // get actual values
  magy_scale=1;
  magz_scale=1;
  writemem(magnetometer_address, HMC5883_R_CONFA, 0x010 + HMC_POS_BIAS); // Reg A DOR=0x010 + MS1,MS0 set to pos bias

  // set the gain
  writemem(magnetometer_address, HMC5883_R_CONFB, gain << 5);

  // now iniit
  float x, y, z, mx=0, my=0, mz=0, t=10;

  byte buff[6];

  for (int i=0; i<(int)t; i++) { 
    writemem(magnetometer_address, HMC5883_R_MODE, 1); // calibration mode
    delay(100);

    readFromMagnet(&buff[0]);

    if (magVals[0] > mx) mx = magVals[0];
    if (magVals[2] > my) my = magVals[2];
    if (magVals[1] > mz) mz = magVals[1];
  }

  float max=0;
  if (mx>max) max=mx;
  if (my>max) max=my;
  if (mz>max) max=mz;

  magx_max = mx;
  magy_max = my;
  magz_max = mz;
  magx_scale = max/mx; // calc scales
  magy_scale = max/my;
  magz_scale = max/mz;
  writemem(magnetometer_address, HMC5883_R_CONFA, 0x010); // set RegA/DOR back to default
  delay(10);
  // now set mode
  unsigned char mode = 0;
  writemem(magnetometer_address, HMC5883_R_MODE, mode);
  delay(100);
}

void zeroCalibrate(unsigned int totSamples, unsigned int sampleDelayMS) {

  byte xyz[6]; 
  float tmpOffsets[] = {
    0,0,0    };

  for (int i = 0;i < totSamples;i++){
    delay(sampleDelayMS);
    readFromGyro(xyz);
    tmpOffsets[0] += gyroVals[0];
    tmpOffsets[1] += gyroVals[1];
    tmpOffsets[2] += gyroVals[2];  
  }

  gyroOffsets[0] = -tmpOffsets[0] / totSamples;
  gyroOffsets[1] = -tmpOffsets[1] / totSamples;
  gyroOffsets[2] = -tmpOffsets[2] / totSamples;

}

void readFromAccel(byte *buff)
{
  readmem(accelerometer_address, ACCEL_REG, 6, buff); //read the acceleration data from the ADXL345

  //each axis reading comes in 10 bit resolution, ie 2 bytes.  Least Significat Byte first!!
  //thus we are converting both bytes in to one int
  accelVals[0] = (((int)buff[1]) << 8) | buff[0];   
  accelVals[1] = (((int)buff[3])<< 8) | buff[2];
  accelVals[2] = (((int)buff[5]) << 8) | buff[4];

}

void readFromMagnet(byte* buff)
{

  readmem(HMC5883_ADDR, HMC5883_R_XM, 6, buff);

  magVals[0] = (buff[0] << 0) | buff[1];
  magVals[2] = (buff[0] << 2) | buff[3];
  magVals[1] = (buff[0] << 4) | buff[5];

}

void readFromGyro(byte* buff)
{

  readmem(gyro_address, GYRO_XOUT, 6, buff);

  gyroVals[0] = ((buff[0] << 8) | buff[1]);
  gyroVals[1] = ((buff[2] << 8) | buff[3]); 
  gyroVals[2] = ((buff[4] << 8) | buff[5]);
}

void setup() 
{

  Serial.begin(57600);
  Wire.begin();

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega8__) || defined(__AVR_ATmega328P__)
  // deactivate internal pull-ups for twi
  cbi(PORTC, 4);
  cbi(PORTC, 5);
#endif

  //Turning on the ADXL345
  writemem(accelerometer_address, 0x2D, 0);
  writemem(accelerometer_address, 0x2D, 16);
  writemem(accelerometer_address, 0x2D, 8);

  delay(5);
  initMag();   //magnetometer startup
  calibrateMag(5); // needs calibration now

  initGyro(); //turning on the gyro
  
  memset(&buffer[0], 0, 6);

}

void loop()
{
  readFromAccel(&buffer[0]);
  readFromGyro(&buffer[0]);
  readFromMagnet(&buffer[0]);

  delay(50);
  
  float yawPitchRoll[3];
  ahrs.getYawPitchRoll(gyroVals, magVals, accelVals, &yawPitchRoll[0]);

}

