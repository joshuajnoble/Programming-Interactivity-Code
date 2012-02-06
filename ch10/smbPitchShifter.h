#include <string.h>
#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846
#define MAX_FRAME_LENGTH 8192

class smbPitchShifter
{
	public:
	static void smbPitchShift(float pitchShift, long numSampsToProcess, long fftFrameSize, long osamp, float sampleRate, float *indata, float *outdata);
	static void smbFft(float *fftBuffer, long fftFrameSize, long sign);
	static double smbAtan2(double x, double y);
	
};