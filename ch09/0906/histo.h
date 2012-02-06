#pragma mark once

#include "ofMain.h"

class histo: public ofBaseApp{

    public:

        void setup();
        void update();
        void draw();

        ofImage img;
        int pxColors[2048]; //the array that will store all the colors
	bool bChange;

};
