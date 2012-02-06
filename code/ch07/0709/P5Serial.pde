import processing.serial.*;

// Declare the serial port that we're going to use
Serial arduinoPort;

void setup() {
    // uncomment the next line if you want to
    // see all the available controllers
    // println(Serial.list());
 arduinoPort = new Serial(this, Serial.list()[0], 9600);
}

void draw() {}

void keyPressed() {
    // Send the key that was pressed
    arduinoPort.write(key);
}