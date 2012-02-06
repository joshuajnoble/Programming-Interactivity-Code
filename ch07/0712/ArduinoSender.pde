int buttonPin = 13;

void setup() {
    // open the serial port at 9600 bps:
    Serial.begin(9600);
}

void loop() {
    if(digitalRead(buttonPin ) == HIGH) {
        Serial.print("!");
    } else {
        Serial.print("?");
    }
    delay(200);
}