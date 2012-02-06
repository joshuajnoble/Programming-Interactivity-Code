#pragma mark once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofGui.h"

class sineJoiner : public ofBaseApp{

	public:
	
	void setup();
	void update() {}
	void draw();
	
	void audioOut 	(float * input, int bufferSize, int nChannels); /* output method */
	
	int		initialBufferSize; /* buffer size */ 
	int		sampleRate;
	
	ofSoundStream soundStream;
	
	// begin maximilian stuff
	double outputs[2];
	ofxMaxiOsc sine, phasorSine, phasor;
	
	int bin_number;
	float largest;
	
	ofxMaxiMix mix;
	ofxMaxiFilter filterlo;
	
	ofSlider slider1, slider2, slider3;
	ofGuiCollection gui;
	
	float waves[512];
	float phasors[512];
	
};

