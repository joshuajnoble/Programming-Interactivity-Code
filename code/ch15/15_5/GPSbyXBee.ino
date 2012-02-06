#include "SoftwareSerial.h"
#include "TinyGPS.h"

#define SSRXPIN 3
#define SSTXPIN 2

Example 15-4 GPSbyXBee.ino
SoftwareSerial serial(SSRXPIN , SSTXPIN );
TinyGPS gps;

long lat, lon;
char myName[] = "joshua n";

void setup() {
    Serial.begin(9600);
}

void loop()
{
    while (serial.available())
    {
        int c = serial.read();
        if (gps.encode(c))
        {
            gps.get_position(&lat, &lon, 0);
            Serial.print(myName);
            Serial.print(':');
            Serial.print(lat,DEC);
            Serial.print(',');
            Serial.print(lon,DEC);
        }
    }
    delay(60000); // send our name and location every minute;
}
