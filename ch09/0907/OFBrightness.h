#pragma mark once

#include "ofMain.h"

#define grabbedVidWidth 320
#define grabbedVidHeight 240

class OFBrightness : public ofBaseApp
{
    public:

        void setup();
        void update();
        void draw();

        unsigned char* drawingPixels;
        int brightestLoc[2];
        ofVideoGrabber videoIn;

};
