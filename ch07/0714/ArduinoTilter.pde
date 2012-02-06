int xpin = 2;         // x-axis of the accelerometer
int ypin = 1;         // y-axis
int zpin = 0;         // z-axis (only on 3-axis models)

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.print(analogRead(xpin));
    Serial.print(" ");
    Serial.print(analogRead(ypin));
    Serial.print(" ");
    Serial.println(analogRead(zpin));
    delay(50);
}