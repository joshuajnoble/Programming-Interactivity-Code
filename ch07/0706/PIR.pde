int alarmPin = 3;    // motion alarm output from PIR
int ledPin = 13;     // output pin for the LED
int motionAlarm = 0;

void setup(){
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

void loop(){
    motionAlarm = digitalRead(alarmPin);
    // this is a very simple loop that lights an LED if motion detected
    if(motionAlarm == HIGH){
        digitalWrite(ledPin, HIGH);// we've detected motion
        delay(500);
        digitalWrite(ledPin, LOW); // turn off the light
    }
}