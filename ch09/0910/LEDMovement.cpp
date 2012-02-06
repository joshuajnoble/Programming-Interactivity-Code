#include "LEDMovement.h"

void LEDMovement::setup() {
	
    videoIn.initGrabber(GRABBED_VID_WIDTH ,GRABBED_VID_HEIGHT);
    serial.setup("/dev/tty.usbserial-A4000Qek", 9600);
    totalPixels = GRABBED_VID_WIDTH*GRABBED_VID_HEIGHT*3;
}

void LEDMovement::update() {
	
    videoIn.grabFrame();
	
    if (videoIn.isFrameNew()) {
        unsigned char * tempPixels = videoIn.getPixels();
        int i;
        for(i = 0; i < 64; i++) {
            motionVals[i] = 0;
        }
		
        for (i = 0; i < totalPixels; i+=3) {
            unsigned char r = abs(tempPixels[i] - dataPixels[i]);
            unsigned char g = abs(tempPixels[i+1] - dataPixels[i+1]);
            unsigned char b = abs(tempPixels[i+2] - dataPixels[i+2]);
			
            int diff = r+g+b;
            if (diff > 70)  {
                motionVals[totalPixels/3600]++;
            }
			
            tempPixels[i] = dataPixels[i];
            tempPixels[i+1] = dataPixels[i+1];
            tempPixels[i+2] = dataPixels[i+2];
			
        }
		
		for(i = 0; i < 64; i++)
		{
			if(motionVals[i] > 100) {
				
				serial.writeByte(i % 8);
				serial.writeByte(i / 8);
				serial.writeByte('x');
			}
		}
	}
}

void LEDMovement::draw(){
    ofSetColor(0xffffff);
    videoIn.draw(20,20);
}
