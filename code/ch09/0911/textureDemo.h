#pragma mark once

#include "ofMain.h"

class textureDemo : public ofBaseApp{

    public:

        void setup();
        void update();
        void draw();
        void mouseMoved(int x, int y );

        ofTexture colorTexture;
        int             w, h;
        ofPixels colorPixels;
	
	float blue;
	bool countUp;

};
