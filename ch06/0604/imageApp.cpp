#include "imageApp.h"

void imageApp::setup(){
    milkShakeImg.loadImage("http://programminginteractivity.com/milkshake.jpg");
	friesImg.loadImage("http://programminginteractivity.com/fries.jpg");
}

void imageApp::update()
{
	friesPosition.y = sin( ofGetElapsedTimef() ) * 50;
	shakePosition.x = cos( ofGetElapsedTimef() ) * 50;
}

void imageApp::draw(){

	ofBackground(255,255,255);
	friesImg.draw( friesPosition.x, friesPosition.y );
	milkShakeImg.draw( shakePosition.x, shakePosition.y );
}