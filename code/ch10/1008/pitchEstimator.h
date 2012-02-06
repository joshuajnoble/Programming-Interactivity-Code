#pragma mark once


#include "ofMain.h"
#include "ofxMaxim.h"


class pitchEstimator : public ofBaseApp{

	public:
	
	~pitchEstimator();
	void setup();
	void update();
	void draw();
	
	void audioOut 	(float * input, int bufferSize, int nChannels); /* output method */
	void audioIn 	(float * input, int bufferSize, int nChannels); /* input method */
	
	int		initialBufferSize; /* buffer size */ 
	int		sampleRate;
	
	ofSoundStream soundStream;
	
	// begin maximilian stuff
	
	double wave,wave1, wave2, sample,outputs[2];
	//ofxMaxiOsc sines[13];
	ofxMaxiOsc sine, sine1, sine2;
	
	int bin_number, bin_number1, bin_number2;
	float largests[3];
	
	ofxMaxiFilter lowpass, highpass;
	
	ofxMaxiFFT fft;
	ofxMaxiFFTOctaveAnalyzer octaveAnalyzer;
	ofxMaxiMix mix;

	float *inputL, *inputR;
	
	float estimatedPitch[3];
	
};

