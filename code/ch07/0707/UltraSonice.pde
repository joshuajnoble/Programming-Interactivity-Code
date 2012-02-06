long echo = 0;
int usPin = 9; // Ultrasound signal pin
long val = 0;
void setup() {
    Serial.begin(9600);
}

long ping(){
    pinMode(usPin, OUTPUT); // Switch signalpin to output
    digitalWrite(usPin, LOW); // Send low pulse
    delayMicroseconds(2); // Wait for 2 microseconds
    digitalWrite(usPin, HIGH); // Send high pulse
    delayMicroseconds(5); // Wait for 5 microseconds
    digitalWrite(usPin, LOW); // Holdoff
    pinMode(usPin, INPUT); // Switch signalpin to input
    digitalWrite(usPin, HIGH); // Turn on pullup resistor
    echo = pulseIn(usPin, HIGH); // Listen for echo
    long ultrasoundValue = (echo / 58.138);
    return ultrasoundValue;
}

void loop() {
    long x = ping();
    Serial.println(x);
    delay(250); //delay 1/4 seconds.
}