#pragma mark once
#include "ofMain.h"

class imageApp : public ofBaseApp{

    public:

        void setup();
        void update();
        void draw();

        ofImage milkShakeImg;
        ofImage friesImg;
	
		ofVec2f friesPosition;
		ofVec2f shakePosition;
};
