#include "gestureRec.h"

void gestureRec::setup(){
	num_created_gestures = 0;
	ofBackground(0,0,0);
	createNewGesture();

	mode = 0;
}

void gestureRec::update(){
	if(mode == 1 && ofGetElapsedTimeMillis() >= hide_message_on) {
		mode = 0;
		found_gesture.clear();
	}
}

void gestureRec::draw(){

	if(mode == 0) {	
		ofSetColor(255, 255, 0);
		line.draw();
	} else if (mode == 1) {
		ofSetColor(255, 0, 140);
		ofDrawBitmapString(message, 10, ofGetHeight()-40);
	}
	
	ofSetColor(0, 255, 140);
	found_gesture.draw();  
	
	ofColor(255, 255, 0.0f);
	ofDrawBitmapString("Number of gestures: " +ofToString(dollar.gestures.size()), 10, ofGetHeight()-25);
	ofDrawBitmapString("Name of current gesture: " +gesture->name, 10, ofGetHeight()-10);
}

void gestureRec::mouseDragged(int x, int y, int button){
	if(mode == 0) {
		line.addVertex(ofVec2f(x,y));
	}
}

void gestureRec::showMessage(string sMessage) {
	message = sMessage;
	mode = 1;
	hide_message_on = ofGetElapsedTimeMillis()+1000;
}

void gestureRec::showMessage(string sMessage, int nDelay) {
	message = sMessage;
	mode = 1;
	hide_message_on = ofGetElapsedTimeMillis() + nDelay;
}

void gestureRec::createNewGesture() {
	++num_created_gestures;
	gesture = new ofxGesture();
	gesture->setName("Gesture#" +ofToString(num_created_gestures));
}

void gestureRec::keyPressed( int key ) {
			
		switch(key) {
			case 'c':
				line.clear();
				break;
			case 'm':
				// Add all the point we've just drawn to the gesture. This creates a "gesture".
				gesture->reset(); 
				for(int i = 0; i < line.size(); ++i) {
					gesture->addPoint(line[i].x, line[i].y);
				}
				
				if(gesture->points.size() <= 10) {
					message = "Please add a line first";
				}
				else {
					dollar.addGesture(gesture);
					message = "Added gesture to recognizer";
					line.clear();
					createNewGesture();
				}
				showMessage(message, 800);
				line.clear();
				break;
			case 's':
				dollar.save(ofToDataPath("gestures.txt",true));
				showMessage("Saved!");
				break;
			case 'l': 
				dollar.load(ofToDataPath("gestures.txt",true));
				showMessage("Loaded! Note that saved gestures are rotated to the optimal position!",4000);
				break;
			case 'f':
				// find the gesture which matches the current line.
				ofxGesture* tmp = new ofxGesture();
				for(int i = 0; i < line.size(); ++i) {
					tmp->addPoint(line[i].x, line[i].y);
				}
				line.clear();
				double score = 0.0;
				ofxGesture* match = dollar.match(tmp, &score);
				string result = "Matching score: " +ofToString(score);
				if(match != NULL) {		
					result +=", which matches with gesture: " +match->name;
					found_gesture.clear();
					float dx = ofGetWidth()/2;
					float dy = ofGetHeight()/2;
					for(int i = 0; i < match->resampled_points.size(); ++i) {
						found_gesture.addVertex(ofVec2f(dx+match->resampled_points[i].x, dy+match->resampled_points[i].y));
					}
				}
				showMessage(result, 1500);
				delete tmp;
				break;
	}
}