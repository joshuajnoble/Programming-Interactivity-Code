#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#include "ofMain.h"

#include "ofxXmlSettings.h"
#include "ofTapGestureRecognizer.h"
#include "ofPinchGestureRecognizer.h"
#include "ofSwipeGestureRecognizer.h"
#include "ofPinchEvent.h"

class pinchApp : public ofxiPhoneApp{

	public:

		void setup();
		void update();
		void draw();

		void touchDown(ofTouchEventArgs &touch);
		void touchMoved(ofTouchEventArgs &touch);
		void touchUp(ofTouchEventArgs &touch);
		void touchDoubleTap(ofTouchEventArgs &touch);
		void touchCancelled(ofTouchEventArgs &touch);
	
	ofTapGestureRecognizer *tapper;
	ofPinchGestureRecognizer *pincher;
	ofSwipeGestureRecognizer *swiper;
	void handlePinch(ofPinchEventArgs &e);
	
	ofEvent<ofPinchEventArgs> ofPinchEvent;
};

