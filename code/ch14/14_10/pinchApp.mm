#include "pinchApp.h"


//--------------------------------------------------------------
void pinchApp::setup(){

	// register touch events
	ofxRegisterMultitouch(this);
	
	//iPhoneAlerts will be sent to this.
	ofxiPhoneAlerts.addListener(this);
	
	ofxiPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);

	ofBackground(255,255,255);
	
	EAGLView *view = ofxiPhoneGetGLView();  
	tapper = [[ofTapGestureRecognizer alloc] initWithView:view];  
	swiper = [[ofSwipeGestureRecognizer alloc] initWithView:view];  
	pincher = [[ofPinchGestureRecognizer alloc] initWithView:view]; 
	
	ofAddListener(ofPinchEvent, this, &testApp::handlePinch);

}

void pinchApp::handlePinch(ofPinchEventArgs &e) {
	cout << " got a pinch " << e.velocity << " " << e.scale << endl;
}


//--------------------------------------------------------------
void pinchApp::update(){

}

//--------------------------------------------------------------
void pinchApp::draw(){

	
}

//--------------------------------------------------------------
void pinchApp::touchDown(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void pinchApp::touchMoved(ofTouchEventArgs &touch){
	
}

//--------------------------------------------------------------
void pinchApp::touchUp(ofTouchEventArgs &touch){
	
}

//--------------------------------------------------------------
void pinchApp::touchDoubleTap(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void pinchApp::touchCancelled(ofTouchEventArgs& args){

}



