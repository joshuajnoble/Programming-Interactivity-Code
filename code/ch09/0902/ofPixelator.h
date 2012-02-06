#pragma once

#include "ofMain.h"

class ofPixelator : public ofBaseApp{

    public:

	void setup();
	void update();
	void draw();
	
	void keyPressed( int key );
	
	ofImage image, modImage;
	ofPixels pix;

};
