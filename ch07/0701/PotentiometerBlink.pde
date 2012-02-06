int potentiometerPin = 0;
int ledPin = 13;
int val = 0;

void setup(){
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    val = analogRead(potentiometerPin);
    Serial.println(val);
    digitalWrite(ledPin, HIGH);
    delay(val);
    digitalWrite(ledPin, LOW);
    delay(val);
}