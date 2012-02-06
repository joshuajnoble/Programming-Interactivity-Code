#include <SoftwareSerial.h>

// the pin that we'll connect to the reader to activate it
#define ACTIVATE_PIN 4
 
int  val = 0;
char code[10];
int bytesread = 0; 
 
// RFID reader SOUT pin gets connected to pin8
#define rxPin 8
#define txPin 9
 
// this reads the data from the RFID reader. You can find out more
// about the SoftwareSerial here: http://www.arduino.cc/en/Reference/SoftwareSerial
// but to keep it simple: we need to talk to the Processing application with the
// hardware serial, so we use a "fake" software serial to read from the RFID reader
SoftwareSerial serial(8, 9);
int gameMode;
 
void setup()
{
 
  Serial.begin(9600); // serial to write to Processing applicaiton
  serial.begin(2400);  // serial to read from RFID reader at 2400bps
 
  pinMode(ACTIVATE_PIN,OUTPUT);       // Set digital pin 4 as OUTPUT to connect it to the RFID /ENABLE pin
  digitalWrite(ACTIVATE_PIN, LOW);    // Activate the RFID reader 
}
 
void loop()
{
    digitalWrite(ACTIVATE_PIN, LOW);
    if((val = serial.read()) == 10)
    {   // check for header
      bytesread = 0;
      while(bytesread<10)
      {  // read 10 digit code
        val = serial.read();
        if((val == 10)||(val == 13))
        {  // if header or stop bytes before the 10 digit reading
          break;                       // stop reading
        }
        code[bytesread] = val;         // add the digit
        bytesread++;                   // ready to read next digit
      } 
 
      // if 10 digit read is complete
      if(bytesread == 10)
      {
        Serial.write(code); // now send it to the Processing application!
      }
      bytesread = 0;
      delay(500);                       // wait for a 1/2 second just so we don't flood the Processing application
    }
} 
 
// they've pressed the "Check Sandwich" button, so let's tell the Processing application!
void checkSandwich()
{
  Serial.write("X");
}