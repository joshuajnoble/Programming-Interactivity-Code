
//here's the I2C library
#include <Wire.h>

char SMPLRT_DIV= 0x15;
char DLPF_FS = 0x16;
char GYRO_X_H = 0x1D;
char GYRO_X_L = 0x1E;
char GYRO_Y_H = 0x1F;
char GYRO_Y_L = 0x20;
char GYRO_Z_H = 0x21;
char GYRO_Z_L = 0x22;

//This is a list of settings that can be loaded into the registers.
//DLPF, Full Scale Register Bits
//FS_SEL must be set to 3 for proper operation
//Set DLPF_CFG to 3 for 1kHz Fint and 42 Hz Low Pass Filter
char DLPF_CFG_0 = (1<<0);
char DLPF_CFG_1 = (1<<1);
char DLPF_CFG_2 = (1<<2);
char DLPF_FS_SEL_0 = (1<<3);
char DLPF_FS_SEL_1 = (1<<4);

//I2C devices each have an address. The address is defined in the datasheet for the device. The ITG-3200 breakout board can have different address depending on how
//the jumper on top of the board is configured. By default, the jumper is connected to the VDD pin. When the jumper is connected to the VDD pin the I2C address
//is 0x69.
const char ITGADDRESS = 0x69;

//In the setup section of the sketch the serial port will be configured, the i2c communication will be initialized, and the itg-3200 will be configured.
void setup()
{
  Serial.begin(9600);
  
  //Initialize the I2C communication. This will set the Arduino up as the 'Master' device.
  Wire.begin();
  
  //Configure the gyroscope
  i2cWrite(DLPF_FS, 11001b);
  //Set the sample rate to 100 hz
  i2cWrite(SMPLRT_DIV, 9);
}

//The loop section of the sketch will read the X,Y and Z output rates from the gyroscope and output them in the Serial Terminal
void loop()
{
  //Create variables to hold the output rates.
  int xRate, yRate, zRate;

  //Read the x,y and z output rates from the gyroscope.
  xRate = i2cRead(GYRO_X_H)<<8;
  xRate |= i2cRead(GYRO_X_L);  
  
  yRate = i2cRead(GYRO_Y_H)<<8;
  yRate |= i2cRead( GYRO_Y_L);  
  
  zRate = i2cRead( GYRO_Z_H)<<8;
  zRate |= i2cRead( GYRO_Z_L);  

  Serial.print("x: ");
  Serial.print(xRate);
  Serial.print(" y: ");
  Serial.print(yRate);
  Serial.print(" z: ");
  Serial.println(zRate);  

  delay(10);
}

//This function will write a value to a register on the itg-3200.
//Parameters:
//  char address: The I2C address of the sensor. For the ITG-3200 breakout the address is 0x69.
//  char registerAddress: The address of the register on the sensor that should be written to.
//  char data: The value to be written to the specified register.
void i2cWrite(char registerAddress, char data)
{
  //Initiate a communication sequence with the desired i2c device
  Wire.beginTransmission(ITGADDRESS);
  //Tell the I2C address which register we are writing to
  Wire.send(registerAddress);
  //Send the value to write to the specified register
  Wire.send(data);
  //End the communication sequence
  Wire.endTransmission();
}

unsigned char i2cRead(char registerAddress)
{
  //This variable will hold the contents read from the i2c device.
  unsigned char data=0;
  
  //Send the register address to be read.
  Wire.beginTransmission(ITGADDRESS);
  //Send the Register Address
  Wire.send(registerAddress);
  //End the communication sequence.
  Wire.endTransmission();
  
  //Ask the I2C device for data
  Wire.beginTransmission(ITGADDRESS);
  Wire.requestFrom(address, 1);
  
  //Wait for a response from the I2C device
  if(Wire.available()){
    //Save the data sent from the I2C device
    data = Wire.receive();
  }
  
  //End the communication sequence.
  Wire.endTransmission();
  
  //Return the data read during the operation
  return data;
}
