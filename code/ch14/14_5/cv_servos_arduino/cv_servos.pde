#define DSERVO_TWO_X_PIN 3
#define DSERVO_TWO_Y_PIN 4

#include <Servo.h>

const float ratio = 0.7058; // 180 / 255

Servo vert;
Servo horz;
byte target[2];
byte current[2];

void setup() {
  horz.attach(3);
  vert.attach(5);
  
  memset(target, 0, 2);
  memset(current, 0, 2);
  
  Serial.begin(9600);
  
}

void loop() {
  
  // if we've gotten new positions store them
  if(Serial.available() > 1) {
    target[0] = Serial.read();
    target[1] = Serial.read();
  }
  
  // if our x position needs to be updated lerp to it
  if(abs(target[0] - current[0]) > 1) {
     // now that we have the xy we can go ahead
    // and write them to the serial
    horz.write(target[0] * ratio);
  }

  // if our x position needs to be updated lerp to it  
  if(abs(target[1] - current[1]) > 1) {
     // now that we have the xy we can go ahead
    // and write them to the serial
    horz.write((0.5, target[1], current[1]) * ratio);
  }
}

byte lerp(float t, byte a, byte b)
{ 
  return a + t * (b - a); 
}

