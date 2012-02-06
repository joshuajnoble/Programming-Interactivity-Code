#include "bezierGraphics.h"

void bezierGraphics::setup(){
    ofSetCircleResolution(100);
    ofBackground(255,255,255);
	ofSetVerticalSync(true);
	
	fillColor.setHue(0);
	fillColor.setSaturation(255.f);
	fillColor.setBrightness(255.f);
	
}

void bezierGraphics::update()
{
	fillColor.setHue(fillColor.getHue()+1);
	if(fillColor.getHue() > 254) fillColor.setHue(0);
	
}


void bezierGraphics::draw(){

	float bez1X1 = 400 + (100 * cos(ofGetElapsedTimef()));
	float bez1Y1 = 500 + (100 * sin(ofGetElapsedTimef()));
	float bez1X2 = 600 + (100 * cos(ofGetElapsedTimef()));
	float bez1Y2 = 500 + (100 * sin(ofGetElapsedTimef()));

	float bez2X1 = 400 - (100 * cos(ofGetElapsedTimef()));
	float bez2Y1 = 500 - (100 * sin(ofGetElapsedTimef()));
	float bez2X2 = 600 - (100 * cos(ofGetElapsedTimef()));
	float bez2Y2 = 500 - (100 * sin(ofGetElapsedTimef()));

	
	ofFill();
	ofSetHexColor(0xffffff - fillColor.getHex());
	ofBeginShape();
		// first we create the point from which to begin drawing
		ofVertex(0,300);
		// then create the Bezier vertex
		ofBezierVertex(bez1X1,bez1Y1,bez1X2,bez1Y2,900,300);
		ofBezierVertex(bez2X1,bez2Y1,bez2X2,bez2Y2,100,300);
		// finish the shape
		ofVertex(1000,300);
	ofEndShape();
	
	ofFill();
	ofSetColor(fillColor);
	ofBeginShape();
		ofVertex(0,300);
		ofBezierVertex(650,300,bez2X2,bez2Y2,900,300);
		ofBezierVertex(100,300,bez1X2,bez1Y2,100,300);
		ofVertex(1000,300);
	ofEndShape();

}