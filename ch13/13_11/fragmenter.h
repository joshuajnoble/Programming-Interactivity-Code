#pragma once

#include "ofMain.h"

struct coord {
	ofVec3f* pos;
	ofVec2f* tx;
};

class fragmenter : public ofBaseApp{

public:

    void setup();
    void update();
    void draw();

    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);


	ofShader fragmentator;
	vector<coord> coords;
	float rot;
	ofVideoGrabber grab;
	
    int cubeLengths;
	int vidWidth, vidHeight;
	
	bool mouseIsDown;
	
};
