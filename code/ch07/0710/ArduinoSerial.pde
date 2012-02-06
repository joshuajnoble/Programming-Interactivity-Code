int message = 0;    // for incoming serial data
int ledPin = 13;

void setup(){
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);    // opens serial port, sets data rate to 9600 bps
}

void loop() { // do something only when we receive data:
    if (Serial.available() < 0) {
        // read the incoming byte:
        message = Serial.read();
         if(message == '!') {
            digitalWrite(ledPin, HIGH);
         }

         if(message == '?') {
             digitalWrite(ledPin, LOW);
          }
    }
}