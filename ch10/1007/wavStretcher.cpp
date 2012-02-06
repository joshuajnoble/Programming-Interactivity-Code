
#include "wavStretcher.h"


wavStretcher::~wavStretcher()
{
	delete ts; // clean up after yourself!
}


void wavStretcher::setup()
{
	
	//samples from http://freesound.org
	samp.load(ofToDataPath("organ.wav"));

	ofEnableAlphaBlending();
	ofSetupScreen();
	ofBackground(0, 0, 0);
	ofSetFrameRate(60);
	
	sampleRate 			= 44100; /* Sampling Rate */
	initialBufferSize	= 512;	/* Buffer Size. you have to fill this buffer with sound*/
			   	
	ts = new maxiTimestretch<hannWinFunctor>(&samp);
	
	stretches.push_back(ts);
	
	speed = 1;
	grainLength = 0.05;
	current=0;
	
	fft.setup(1024, 512, 256);
	octaveAnalyser.setup(44100, 1024, 10);
	
	int current = 0;
	ofxMaxiSettings::setup(sampleRate, 2, initialBufferSize);
	ofSoundStreamSetup(2,0, this, maxiSettings::sampleRate, initialBufferSize, 4);/* Call this last ! */
	
}

void wavStretcher::update()
{
	//nada
}

void wavStretcher::draw()
{	
	
	ofSetColor(255, 255, 255, 255);
	int i;
	ofBeginShape();
	ofVertex(50, ofGetHeight()/2);
	for(i = 0; i < octaveAnalyser.nAverages; i++) {
		// you can draw them as simple rects
		//ofRect( 50 + i * 10, ofGetHeight()/2 - (octaveAnalyser.averages[i] * 4), 10, octaveAnalyser.averages[i] * 8);
		// or as peaks+troughs
		ofVertex(50 + i * 10, ofGetHeight()/2 - (octaveAnalyser.averages[i] * 4));
		ofVertex(50 + i * 10, ofGetHeight()/2 + octaveAnalyser.averages[i] * 4);
	}
	ofVertex(ofGetWidth(), ofGetHeight()/2);
	ofEndShape(true);
}

void wavStretcher::audioRequested 	(float * output, int bufferSize, int nChannels)
{
	for (int i = 0; i < bufferSize; i++){
		wave = stretches[current]->play(speed, grainLength, 5, 0);
		//wave = stretches[current]->play(speed, 0.1, 4, 0);
		if (fft.process(wave)) {
			octaveAnalyser.calculate(fft.magnitudes);
		}
		
		//play result
		mymix.stereo(wave, outputs, 0.5);
		output[i*nChannels    ] = outputs[0]; /* You may end up with lots of outputs. add them here */
		output[i*nChannels + 1] = outputs[1];
	}
}

void wavStretcher::mouseDragged(int x, int y )
{
	speed = ((double ) x / ofGetWidth() * 4.0) - 2.0;
	grainLength = ((double) y / ofGetHeight() * 0.1) + 0.001;
	pos = ((double) x / ofGetWidth() * 2.0);
	
}

