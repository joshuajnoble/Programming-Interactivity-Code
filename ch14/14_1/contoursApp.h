#pragma mark once

#include "ofMain.h"
#include "ofxOpenCv.h"

class contoursApp : public ofBaseApp{

public:

    void setup();
    void update();
    void draw();

    void keyPressed  (int key);

    ofVideoGrabber vidGrabber;
	ofxCvColorImage colorImg;
	
	ofxCvGrayscaleImage grayImage;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    ofxCvContourFinder contourFinder;
    int threshold;
    bool bLearnBackground;
};
