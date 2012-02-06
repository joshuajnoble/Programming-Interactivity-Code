#include "moveTracker.h"


void moveTracker::setup(){
    totalPixels = GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT * 3;
    videoIn.initGrabber(GRABBED_VID_WIDTH ,GRABBED_VID_HEIGHT);
    lastFrame.allocate(GRABBED_VID_WIDTH ,GRABBED_VID_HEIGHT, OF_IMAGE_COLOR);
    movement.allocate(GRABBED_VID_WIDTH ,GRABBED_VID_HEIGHT, OF_IMAGE_COLOR);
}

void moveTracker::update(){
	
    videoIn.grabFrame();
	
    if(videoIn.isFrameNew())
    {
        unsigned char * lastFramePix = lastFrame.getPixels();
        unsigned char * videoPix = videoIn.getPixels();
        unsigned char * movementPix = movement.getPixels();
        
        for (int i = 0; i < totalPixels; i+=3)
        {
            unsigned char r = abs(lastFramePix[i] - videoPix[i]);
            unsigned char g = abs(lastFramePix[i+1] - videoPix[i+1]);
            unsigned char b = abs(lastFramePix[i+2] - videoPix[i+2]);
			
			int diff = r+g+b;
            if (diff > 40) {
                movementPix[i] = 255;
                movementPix[i+1] = 255;
                movementPix[i+2] = 255;
            } else {
                movementPix[i] = 0;
                movementPix[i+1] = 0;
                movementPix[i+2] = 0;
            }
        }
        
        movement.setFromPixels(movementPix, GRABBED_VID_WIDTH, GRABBED_VID_HEIGHT, OF_IMAGE_COLOR);
        lastFrame.setFromPixels(videoPix, GRABBED_VID_WIDTH, GRABBED_VID_HEIGHT, OF_IMAGE_COLOR);
    }
}

void moveTracker::draw(){
	
    ofSetHexColor(0xffffff);
    videoIn.draw(20,20);
    movement.draw(20+GRABBED_VID_WIDTH, 20);
}