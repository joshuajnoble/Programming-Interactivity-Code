
#include <Stepper.h>

Stepper stepper(100, 8, 9, 10, 11); // note that we don't use = new Stepper();

void setup()
{
    // set the speed of the motor to 50 RPM
    stepper.setSpeed(50);
}

void loop()
{
    stepper.step(1);
    delay(500);
    stepper.step(2);
    delay(500);
    stepper.step(2);
    delay(500);
}