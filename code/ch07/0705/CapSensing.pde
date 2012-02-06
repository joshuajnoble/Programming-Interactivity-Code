#include <CapSense.h>

CapSense cSensor(4,2);        // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil

void setup()                    
{
   Serial.begin(9600);
}

void loop()                    
{
    long sensor =  cSensor.capSense(30);
    Serial.print(" Reading ");
    Serial.println(sensor);
    delay(50);
}
