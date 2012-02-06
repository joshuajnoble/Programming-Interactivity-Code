#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxBox2d.h"

class boxCV : public ofBaseApp{
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	
	ofVideoGrabber 		vidGrabber;
	ofxCvColorImage			colorImg;
	ofxCvGrayscaleImage 	grayImage;
	ofxCvGrayscaleImage 	grayBg;
	ofxCvGrayscaleImage 	grayDiff;
	ofxCvContourFinder 	contourFinder;
	
	ofxBox2dPolygon			*bodyShape;
	ofxBox2d				box2d;
	
	vector<ofxBox2dCircle> circles;
	int waterfallLEdge, waterfallREdge;
	float radius;
	
	bool debugging, contours;
	bool bLearnBakground;
	
	int		threshold;
	float	amount;	
	
	void checkBlobs();
	
	
};

