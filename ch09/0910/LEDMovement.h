#pragma mark once

#include "ofMain.h"

#define GRABBED_VID_WIDTH 320
#define GRABBED_VID_HEIGHT 240

class LEDMovement : public ofBaseApp{

    public:

        void setup();
        void update();
        void draw();

        int motionVals[64];
        int totalPixels
        unsigned char dataPixels[GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT * 3];
        ofVideoGrabber videoIn;
        ofSerial serial;
};

