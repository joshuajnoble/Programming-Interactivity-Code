int temperatureCommand  = B00000101;  // command used to read temperature
int humidityCommand = B00000011;  // command used to read humidity
int clockPin = 2;  // clock
int dataPin  = 3;  // data
int error;  // to track whether any errors have occurred
float temperature;
float humidity;

void setup() {
    Serial.begin(57600); // open serial at 9600 bps
}

void loop() 
{

    sendOut(temperatureCommand);
    waitForResultSHT();
    int val = getData16SHT();
    skipCrcSHT();
    temperature = (float)val * 0.01 - 40;
    Serial.print("temperature: ");
    Serial.print((long)temperature, DEC);
    //Now we read the humidity
    sendOut(humidityCommand);
    waitForResultSHT();
    val = getData16SHT();
    skipCrcSHT();
    humidity = -4.0 + (.04 * val) + (-0.000003 * val * val);

    Serial.print("humidity: ");
    Serial.print( humidity, DEC);

    delay(600000); // wait for 10 Minutes for next reading?
}

int readIn(int numBits) {
    int ret = 0;

    for (int i=0; i<numBits; ++i) {
        digitalWrite(clockPin, HIGH);
        ret = ret*2 + digitalRead(dataPin);
        digitalWrite(clockPin, LOW);
    }
    return(ret);
}

void sendOut(int command) {

    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    digitalWrite(dataPin, HIGH);
    digitalWrite(clockPin, HIGH);
    digitalWrite(dataPin, LOW);
    digitalWrite(clockPin, LOW);
    digitalWrite(clockPin, HIGH);
    digitalWrite(dataPin, HIGH);
    digitalWrite(clockPin, LOW);

    shiftOut(dataPin, clockPin, MSBFIRST, command);

    // check for errors
   digitalWrite(clockPin, HIGH);
    pinMode(dataPin, INPUT);
    error = digitalRead(dataPin);
    if (error != LOW)
        Serial.println("got an error 0");
    digitalWrite(clockPin, LOW);
    error = digitalRead(dataPin);
    if (error != HIGH)
        Serial.println("got an error 1");
}

void waitForResultSHT() {

    pinMode(dataPin, INPUT);
    for(int i=0; i < 50; ++i) {
        delay(20);
        error = digitalRead(dataPin);
        if (error == LOW)
            break;
    }
    if (error == HIGH)
        Serial.println("got an error 2");
}

int getData16SHT() {
    unsigned int val;

    // get the MSB (most significant bits)
    pinMode(dataPin, INPUT);
    pinMode(clockPin, OUTPUT);
    val = readIn(8);
    val << 8;

    pinMode(dataPin, OUTPUT);
    digitalWrite(dataPin, HIGH);
    digitalWrite(dataPin, LOW);
    digitalWrite(clockPin, HIGH); // toggle pin
    digitalWrite(clockPin, LOW);

    // get the LSB (less significant bits)
    pinMode(dataPin, INPUT);
    val |= readIn(8);
    return val;
}

void skipCrcSHT() {
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    digitalWrite(dataPin, HIGH);
    digitalWrite(clockPin, HIGH); // toggle clock pin
    digitalWrite(clockPin, LOW);
}

