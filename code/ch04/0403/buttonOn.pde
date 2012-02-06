int buttonPin = 10;   // choose the input pin (for a pushbutton)

void setup() {
    // set the pin for the light as an output pin
    pinMode(ledPin, OUTPUT);
    // set the pin for the button as an input pin
    pinMode(buttonPin, INPUT);
}

void loop() {
    // get the value on the pin that the button is connected to
    int val = digitalRead(buttonPin);
    // check if the input is LOW, this will indicate
    // whether the button is pressed
    if (val == 0) {
        // if the button is pressed, then turn the light on
        digitalWrite(lightPin, HIGH);  // turn LED ON
        // otherwise, turn the light on
    } else {
        digitalWrite(lightPin, LOW);  // turn LED OFF
    }
}