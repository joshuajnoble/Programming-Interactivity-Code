int relayPin = 12; // choose the pin for the relay
void setup() {
    pinMode(relayPin, OUTPUT);  // declare relayPin as output
}

void loop(){
    digitalWrite(relayPin, LOW);  // turn relay OFF
    delay(1000);
    digitalWrite(relayPin, HIGH);  // turn relay ON
    delay(1000);
}