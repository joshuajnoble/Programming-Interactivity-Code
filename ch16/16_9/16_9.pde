import processing.serial.*;
Serial serial;  // The serial port
int firstAng = 0;
int secAng = 0;
byte[] inbyte = new byte[4];

void setup() {
    size(400, 400);
    String[] arr = Serial.list();
    if(arr.length &gt; 0) {
        serial = new Serial(this, Serial.list()[0], 9600);
    }
}

void draw() {
    background(122);
    int i = 0;
    boolean changed = false;
    if(serial != null) {
        while (serial.available() &gt; 0) {
            inbyte[i] = byte(serial.read());
            changed = true;
            i++;
        }
        if(changed) {
            firstAng = inbyte[0];
            secAng = inbyte[2];
        }
    }

    ellipse(40, 40, 50, 50);
    line(40, 40, 40+(25*cos(firstAng)), 40+(25*sin(firstAng)));
    ellipse(120, 40, 50, 50);
    line(120, 40, 120+(25*cos(secAng)), 40+(25*sin(secAng)));

}