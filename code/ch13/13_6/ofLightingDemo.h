#pragma once

#include "ofMain.h"

class ofLightingDemo: public ofBaseApp{
	
public:
	
	ofTexture text;
	ofLight light1, light2;
	float ang;
	
	void setup();
	void update();
	void draw();
	
};
