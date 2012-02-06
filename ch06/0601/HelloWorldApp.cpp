
#include "HelloWorldApp.h"

void HelloWorldApp::setup(){
	// no need to do anything here
	cout << " just get started here " << endl;
}

void HelloWorldApp::draw(){
	ofBackground(255, 255, 255); // background white
    ofSetColor(0, 0, 0); // text black
	cout << " say hello " << endl;
    ofDrawBitmapString("HELLO WORLD!", 100,380);
}