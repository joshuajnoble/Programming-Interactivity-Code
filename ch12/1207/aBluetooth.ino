import processing.serial.*;
import cc.arduino.*;

String port = "/dev/tty.ARDUINOBT-BluetoothSeri-1";

Arduino arduino;

void setup()
{
    String arduinoList[] = Arduino.list();
    size(512, 200);
    // find the port that you've configured your Arduino BT to use
    int correctPort = 0;
    for(int i = 0; i < arduinoList.length; i++)
    {
        if(arduinoList[i] == port) {
            correctPort = i;
        }
    }
    // once you find it, create a new Arduino instance
    arduino = new Arduino(this, arduinoList[correctPort ], 115200);
}

void draw() {
    if(arduino != null) {

        arduino.pinMode(12, Arduino.INPUT);
        int analogValue = 0;
	analogValue = arduino.analogRead(0);
        // mapping the analogSensor values (0-1023) to values between 0-255
        int inByte0 = int(map(analogValue,0,1023,0,255));
        println(" anlg "+analogValue);

       int digitalValue = 0;
	// mapping the analogSensor values (0-1023) to values between 0-255
       if(digitalValue == Arduino.HIGH) {
          println(" dig "+digitalValue);
       }
    }
}