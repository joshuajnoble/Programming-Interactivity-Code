/*
 *  NetworkCamClient.h
 *  emptyExample
 *
 *  Created by base on 10/09/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma mark once

#include "ofMain.h"
#include "pixelClient.h"

class NetworkCamClient : public ofBaseApp{
	
public:
	
	void setup();
	void update();
	void draw();
	void keyPressed  (int key);
	
	pixelClient client;
	ofTexture tex;
	bool pixelsLoaded;
	
};