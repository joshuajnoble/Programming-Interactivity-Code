#pragma mark once

#include "ofMain.h"

#define NUM_POINTS 24

class MouseVoronoi : public ofBaseApp{

public:
	
    void setup();
	void update();
    void draw();
	
	void mousePressed( int x, int y, int button );
	
	vector<float> xs;
	vector<float> ys;
	vector<float> d;
	vector<ofColor> c;
	
	bool needRedraw;

	
};
