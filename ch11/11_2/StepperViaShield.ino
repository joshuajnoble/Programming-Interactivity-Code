int dirPin = 2;
int stepperPin = 3;

void setup() {
    pinMode(dirPin, OUTPUT);
    pinMode(stepperPin, OUTPUT);
}

void step(boolean dir,int steps){
    digitalWrite(dirPin,dir);
    delay(50);
    for(int i=0;i<steps;i++){
        digitalWrite(stepperPin, HIGH);
        delayMicroseconds(100);
        digitalWrite(stepperPin, LOW);
        delayMicroseconds(100);
    }
}

void loop(){
    step(true,1600);
    delay(500);
    step(false,1600*5);
    delay(500);
}