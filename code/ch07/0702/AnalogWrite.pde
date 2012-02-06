int potentiometerPin = 0;
int ledPin = 9;
int val = 0;

void setup(){
    // setup isn't doing anything, but we still need it here
}

void loop(){
    val = analogRead(potentiometerPin);
    Serial.println(val);
    analogWrite(ledPin, val/4);
}