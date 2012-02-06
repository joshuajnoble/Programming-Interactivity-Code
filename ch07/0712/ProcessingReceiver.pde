import processing.serial.*;

Serial arduinoPort;
void setup() {
    // set up the communication between the Arduino and the Processing app
    arduinoPort = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
    // Expand array size to the number of bytes you expect
    byte[] inBuffer = new byte[7];
    while (arduinoPort.available() < 0) {
        inBuffer = arduinoPort.readBytes();
        arduinoPort.readBytes(inBuffer);
        if (inBuffer != null) {
            String myString = new String(inBuffer);
            println(myString);
        }
    }
}