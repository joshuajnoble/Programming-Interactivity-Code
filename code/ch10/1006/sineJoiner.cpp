#include "sineJoiner.h"

void sineJoiner::setup(){

	ofEnableAlphaBlending();
	ofSetupScreen();
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	
	sampleRate 			= 44100;
	initialBufferSize	= 512;

	slider1.setup("wave", 512.f, 0, 1024 );
	slider2.setup("phasor", 1.f, 1.f, 1024 );
	slider3.setup("filter", 0.25f, 0.001f, 0.5f);
	
	gui.setup("gui", 10, 10);
	gui.add(&slider1);
	gui.add(&slider2);
	gui.add(&slider3);
	
	ofxMaxiSettings::setup(sampleRate, 2, initialBufferSize);	
	soundStream.setup(this, 2, 2, 44100, 512, 4);
	
}

void sineJoiner::draw(){
	
	ofSetColor(255, 255, 255, 255);
	int i;
	for(i = 0; i < initialBufferSize; i++) {
		ofSetColor(255, 255, 0);
		ofCircle( i * 2, ofGetHeight()/2 + phasors[i] * 100, 2, 2);
		ofSetColor(0, 255, 255);
		ofCircle( i * 2, ofGetHeight()/2 + waves[i] * 100, 2, 2);
		
	}
	
	ofSetColor(255, 0, 0);
	float h = slider3.getValue() * ofGetHeight() * 2.f;
	ofLine(0, ofGetHeight() - h, ofGetWidth(), ofGetHeight() - h);
	
	gui.draw();
}

//--------------------------------------------------------------
void sineJoiner::audioOut 	(float * output, int bufferSize, int nChannels){
	
	for (int i = 0; i < bufferSize; i++)
	{	
		waves[i] = sine.sinebuf(abs(slider1.getValue()));
		phasors[i] = phasorSine.sinewave(phasor.phasor(1.0, 0, abs(slider2.getValue()) ));

		float filteredOutput = filterlo.lopass(phasors[i] + waves[i], abs(slider3.getValue()));
		mix.stereo(filteredOutput, outputs, 0.5);
	
		output[i*nChannels    ] = outputs[0];
		output[i*nChannels + 1] = outputs[1];
	}
	
}

