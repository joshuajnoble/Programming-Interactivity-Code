

#include <Wire.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#ifndef AHRS
#define AHRS

class AHRS
{
  public:
    FreeIMU();
    void init();
    void getQ(float * q);
    void getEuler(float * angles);
    void getYawPitchRoll(float * ypr);
    
	int* raw_acc, raw_gyro, raw_magn;
	void AHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);
    
  private:

    float q0, q1, q2, q3; // quaternion elements representing the estimated orientation
    float iq0, iq1, iq2, iq3;
    float exInt, eyInt, ezInt;  // scaled integral error
    int lastUpdate, now; // sample period expressed in milliseconds
    float halfT; // half the sample period expressed in seconds
    int startLoopTime;
};

#endif // AHRS

