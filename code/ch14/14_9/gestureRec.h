#pragma once
#include "ofMain.h"
#include "ofxOneDollar.h"

enum action{ SAVE, LOAD, MAKE, FIND, CLEAR };

class gestureRec : public ofBaseApp {
	
	public:
	
	void setup();
	void update();
	void draw();
	void keyPressed  (int key);
	void mouseDragged(int x, int y, int button);
	void showMessage(string sMessage, int nDelay);
	void showMessage(string sMessage);

	void createNewGesture();

	ofPolyline line;
	ofPolyline found_gesture;

	ofxOneDollar dollar;
	ofxGesture* gesture;

	int num_created_gestures;
	
	int mode;
	action command;
	string message;
	int hide_message_on;
};
