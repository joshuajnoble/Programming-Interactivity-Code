#pragma once

#include "ofMain.h" // we need to include all the oF files, linked here

class pixelReader : public ofBaseApp{

    public:

	void setup();
	void update();
	void draw();
	void keyPressed( int key );
	
	ofImage pic;
	int location;
	int fullSize;
	ofPixels pixels;
	
	bool drawPixelGrid;
};
