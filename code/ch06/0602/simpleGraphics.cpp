#include "simpleGraphics.h"

void simpleGraphics::setup(){
    ofSetCircleResolution(100);
    ofBackground(255,255,255);
	ofSetVerticalSync(true);
	
	fillColor.set(255, 0, 0);
}

void simpleGraphics::update()
{
	fillColor.setHue(fillColor.getHue()+1);
	
	if(fillColor.getHue() > 254) 
		fillColor.setHue(0);
	
}

void simpleGraphics::draw(){

	ofBackground(255,255,255);
    ofSetColor(fillColor);
    ofFill();        // draw "filled shapes"
    ofCircle(100,400,100);

    // now just an outline
    ofNoFill();
	ofSetLineWidth(10);
    ofSetColor(fillColor);
    ofCircle(400,400,200);

}