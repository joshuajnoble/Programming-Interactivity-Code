#include "OFBrightness.h"

void OFBrightness::setup(){
	
    videoIn.initGrabber(grabbedVidWidth ,grabbedVidHeight);
}

void OFBrightness::update(){
	
    videoIn.grabFrame();
	
    int brightest = 0;
    int index = 0;
	
    if (videoIn.isFrameNew()) { //check to make sure the frame is new
        drawingPixels = videoIn.getPixels();
        int length  = grabbedVidWidth*grabbedVidHeight*3;
        for (int i = 0; i < length; i+=3) {
            unsigned char r = drawingPixels[i];
            unsigned char g = drawingPixels[i+1];
            unsigned char b = drawingPixels[i+2];
			
            if(int(r+g+b) > brightest) {
                brightest = int(r+g+b);
                brightestLoc[0] = (i/3) % grabbedVidWidth;
                brightestLoc[1] = (i/3) / grabbedVidWidth;
            }
        }
    }
}

void OFBrightness::draw(){
    ofSetColor(0xffffff);
    videoIn.draw(0, 0);
    ofEllipse(brightestLoc[0],brightestLoc[1], 10, 10);
}