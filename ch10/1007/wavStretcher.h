#pragma mark once


#include "ofMain.h"
#include "ofxMaxim.h"
#include "maxiGrains.h"
#include <sys/time.h>

class wavStretcher : public ofBaseApp
{

	public:
	
	~wavStretcher(); // this is a destructor, handy in this case
	
	void setup();
	void update();
	void draw();

	void mouseDragged (int x, int y );
	
	void audioRequested (float * input, int bufferSize, int nChannels); // output method
	
	int	initialBufferSize;
	int	sampleRate;
	
	double wave,sample,outputs[2];
	maxiSample samp;
	vector<maxiTimestretch<hannWinFunctor>*> stretches;
	maxiMix mymix;
	maxiTimestretch<hannWinFunctor> *ts;
	double speed, grainLength;
	
	ofxMaxiFFT fft;
	ofxMaxiFFTOctaveAnalyzer octaveAnalyser;
	int current;
	double pos;

};

