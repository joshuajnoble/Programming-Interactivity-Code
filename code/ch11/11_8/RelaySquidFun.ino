void setup() {

    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);

}

void loop() {

    digitalWrite(HIGH, 4);
    delay(1000);
    digitalWrite(LOW, 4);
    digitalWrite(HIGH, 5);
    delay(1000);
    digitalWrite(LOW, 5);
    digitalWrite(HIGH, 6);
    delay(1000);
    digitalWrite(LOW, 6);
    digitalWrite(HIGH, 7);
    delay(1000);
    digitalWrite(LOW, 7);

}