#include "pitchEstimator.h"

pitchEstimator::~pitchEstimator() {
	delete inputL; // clean up after yourself
	delete inputR;
}

void pitchEstimator::setup(){
	/* some standard setup stuff*/

	ofEnableAlphaBlending();
	ofSetupScreen();
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	
	sampleRate 			= 44100;
	initialBufferSize	= 512;
	
	inputL = new float[initialBufferSize];
	inputR = new float[initialBufferSize];
	
	fft.setup(16384, 1024, 512);
	octaveAnalyzer.setup(44100, 1024, 10);

	soundStream.setup(this, 2, 2, 44100, initialBufferSize, 4);
	
	estimatedPitch[0] = estimatedPitch[1] = estimatedPitch[2] = 0.f;
	
}

void pitchEstimator::update(){
	
}

void pitchEstimator::draw(){
	
	ofSetColor(255, 255, 255, 255);
	int i;
	for(i = 0; i < octaveAnalyzer.nAverages; i++) {
		ofRect(i * 11, ofGetHeight()/2 - (octaveAnalyzer.averages[i] * 4), 11, octaveAnalyzer.averages[i] * 8);
	}

}

void pitchEstimator::audioOut 	(float * output, int bufferSize, int nChannels){
	
	for (int i = 0; i < bufferSize; i++)
	{	
		wave = sine.sinebuf4(abs(estimatedPitch[0])) + sine1.sinebuf4(abs(estimatedPitch[1])) + sine1.sinebuf4(abs(estimatedPitch[2]));
		
		mix.stereo(wave/3.f, outputs, 0.5);
		
		output[i*nChannels    ] = outputs[0];
		output[i*nChannels + 1] = outputs[1];
	}
	
}

void pitchEstimator::audioIn 	(float * input, int bufferSize, int nChannels){	

	double lIn, rIn;
	
	int i;
	for (i = 0; i < bufferSize; i++){
		
		lIn = input[i*2];
		if(fft.process(lIn)) {
			fft.magsToDB();
			octaveAnalyzer.calculate(fft.magnitudesDB);
		}
		
		rIn = input[i*2 + 1];
		if(fft.process(rIn)) {
			fft.magsToDB();
			octaveAnalyzer.calculate(fft.magnitudesDB);
		}
		
	}
	
	bin_number = bin_number1 = bin_number2 = 0;
	largests[0] = largests[1] = largests[2] = 0.f;
	for (i = 0; i < fft.bins; i++) {
		if(abs(fft.magnitudesDB[i]) > largests[0]) {
			
			largests[2] = largests[1];
			largests[1] = largests[0];
			largests[0] = abs(fft.magnitudesDB[i]);
			
			bin_number2 = bin_number1;
			bin_number1 = bin_number;
			bin_number = i;
		}
	}
	
	if(largests[0] > 12.0)
		estimatedPitch[0] = ( (float) bin_number / fft.bins) * (sampleRate * 0.5);
	else
		estimatedPitch[0] = 0.f;
	
	if(largests[1] > 12.0)
		estimatedPitch[1] = ( (float) bin_number1 / fft.bins) * (sampleRate * 0.5);
	else
		estimatedPitch[1] = 0.f;
	
	if(largests[2] > 12.0)
		estimatedPitch[2] = ( (float) bin_number2 / fft.bins) * (sampleRate * 0.5);
	else
		estimatedPitch[2] = 0.f;
	
	cout << bin_number << " " << estimatedPitch[0] << " " << octaveAnalyzer.spectrumFrequencySpan << endl;
	
}

