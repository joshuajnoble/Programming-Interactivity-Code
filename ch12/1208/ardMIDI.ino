#include <MIDI.h>
#include <NewSoftSerial.h>

const int ledOnPin = 13;
const int ledOffPin = 12;

void blinkLedOn(byte num) { 	// Basic blink function
  for (byte i=0;i<num;i++) {
    digitalWrite(ledOnPin,HIGH);
    delay(30);
    digitalWrite(ledOnPin,LOW);
    delay(30);
  }
}

void blinkLedOff(byte num) { 	// Basic blink function
    digitalWrite(ledOffPin, HIGH);
    delay(100);
    digitalWrite(ledOffPin, LOW);
}

void setup() {
  pinMode(ledOffPin, OUTPUT);
  pinMode(ledOnPin, OUTPUT);
  MIDI.begin(); // input channel is default set to a NSS on 8+9
}

void loop() {
  // Is there a MIDI message incoming ?
  if (MIDI.read()) {
    // Get the type of the message we caught
    switch(MIDI.getType()) {
      case NoteOn: // right now just note on
	blinkLedOn(MIDI.getData1()); // Blink the LED a number of times
        break;
      case NoteOff:
        blinkLedOff(MIDI.getData1());
        break;
      default:
        break;
    }
  }
}

