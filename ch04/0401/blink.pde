void setup() {
    pinMode(13, OUTPUT);      // sets digital pin 13 as output
}

void loop() {
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
}