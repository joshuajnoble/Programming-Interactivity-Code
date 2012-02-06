#ifndef _VECTOR_GRFX_APP
#define _VECTOR_GRFX_APP

#include "ofMain.h"
#include "ofxVectorGraphics.h"

class VectorGrfxApp : public ofBaseApp{

    public:

        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);

        ofxVectorGraphics output;
        bool capture;

        vector <ofPoint> pts;
        float angles[30];
        int phaseoffset;
        int steps;
};

#endif