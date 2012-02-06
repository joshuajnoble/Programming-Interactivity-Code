#pragma mark once

#include "ofMain.h"

class videoApp : public ofBaseApp{

    public:

        void setup();
        void update();
        void draw();

        ofVideoPlayer player;
        float screenHeight;
        bool isPaused;

        void mouseMoved( int x, int y );
        void keyPressed  (int key);
};
