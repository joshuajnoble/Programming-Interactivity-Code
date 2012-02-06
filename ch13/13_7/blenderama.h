#pragma once

#include "ofMain.h"

#define numCubes 20

class blenderama: public ofBaseApp{
	
public:
	
	float ang;
	int currentLBlend, currentRBlend; // indexes to store the current blending value
	ofImage img; // an image to load a picture for a texture
	ofTexture text; // a texture to use
	ofVec3f cubePos[numCubes]; // an array to store all the text values	
	
	void setup();
	void update();
	void draw();
	void keyPressed  (int key);
};
