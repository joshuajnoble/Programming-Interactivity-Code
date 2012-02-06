#pragma mark once

#include "ofMain.h"

#define GRABBED_VID_WIDTH 320
#define GRABBED_VID_HEIGHT 240

class moveTracker : public ofBaseApp{
	
public:
	
	void setup();
	void update();
	void draw();
	
	ofVideoGrabber videoIn;
    ofImage lastFrame;
    ofImage movement;
    
	int totalPixels;
};