int ledPin = 9;
int amountOfLight = 0;

void setup(){
}

void loop(){
    if(amountOfLight &gt; 254) {
        amountOfLight = 0;
    }
    analogWrite(ledPin, amountOfLight);
    amountOfLight+=1;
    delay(10);
}