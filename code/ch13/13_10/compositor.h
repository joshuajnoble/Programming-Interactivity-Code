#pragma once

#include "ofMain.h"

class compositor : public ofBaseApp{

	public:
	
	void setup();
	void update();
	void draw();

	void mouseMoved(int x, int y );

	ofShader shader;
	ofImage background;
	
	ofVideoGrabber grab;

	
};
