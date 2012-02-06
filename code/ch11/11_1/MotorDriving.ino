int switchPin = 2;    // switch input
int motorPin1 = 3;    // H-bridge leg 1
int motorPin2 = 4;    // H-bridge leg 2
int speedPin = 9;     // H-bridge enable pin
int ledPin = 13;      //LED

void setup() {
    // set the switch as an input:
    pinMode(switchPin, INPUT);

    // set all the other pins you're using as outputs:
    pinMode(motorPin1 , OUTPUT);
    pinMode(motorPin2 , OUTPUT);
    pinMode(speedPin, OUTPUT);
    pinMode(ledPin, OUTPUT);

    // set speedPin high so that motor can turn on:
    digitalWrite(speedPin, HIGH);

    // this is borrowed from Tom Igoe and is a nice way to debug
    // your circuit, if the light blinks 3 times after the initial
    // startup that's probably an indication that the Arduino has reset itself
    // because the motor caused a short
    blinkLED(ledPin, 3, 100);
}

void loop() {
    if (digitalRead(switchPin) == HIGH) {
        digitalWrite(motorPin1, LOW);   // set 1A on the H-bridge low
        digitalWrite(motorPin2, HIGH);  // set 2A on the H-bridge high
    } else {
        digitalWrite(motorPin1, HIGH);  // set 1A on the H-bridge high
        digitalWrite(motorPin2, LOW);   // set 2A on the H-bridge low
    }
}

// this method just blinks an LED for debugging
void blinkLED(int whatPin, int howManyTimes, int milliSecs) {
    int i = 0;
    for ( i = 0; i < howManyTimes; i++) {
        digitalWrite(whatPin, HIGH);
        delay(milliSecs/2);
        digitalWrite(whatPin, LOW);
        delay(milliSecs/2);
    }
}