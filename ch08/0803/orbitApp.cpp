#include "orbitApp.h"


//--------------------------------------------------------------
void orbitApp::setup(){

	ofSetFrameRate(60);
	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);
	ofEnableSmoothing();
	
	for( int i = 0; i < 10; i++) {
		planet p;
		p.radius = ofRandom(40) + 5.f;
		
		p.pos.x = ofRandom(400);
		p.pos.y = ofRandom(400);
		
		p.orbitSize = ofRandom( 2.0 ) + 0.5;
		
		p.color.set( ofRandom(255), ofRandom(255), ofRandom(255) );
		planets.push_back(p);
		
	}
	
}

//--------------------------------------------------------------
void orbitApp::update(){
	
	float amplitude = 200.0;

	int i = 0;
	
	while( i < planets.size() ) {
		
		float wavelength = 20.f * planets.at(i).orbitSize;

		planets.at(i).pos.x = amplitude * planets.at(i).orbitSize * cos(ofGetFrameNum() / wavelength ) + mouseX;
		planets.at(i).pos.y = amplitude * planets.at(i).orbitSize * sin(ofGetFrameNum() / wavelength ) + mouseY;

		i++;
	}
}

//--------------------------------------------------------------
void orbitApp::draw(){

	ofFill();
	
	int i = 0;
	
	while( i < planets.size() ) {
		ofSetColor(planets.at(i).color);
		ofCircle(planets.at(i).pos.x, planets.at(i).pos.y, planets.at(i).radius);		
		i++;
	}
}

//--------------------------------------------------------------
void orbitApp::keyPressed(int key){

	planet p;
	p.radius = ofRandom(40) + 5.f;
	
	p.pos.x = ofRandom(400);
	p.pos.y = ofRandom(400);
	
	p.orbitSize = ofRandom( 2.0 ) + 0.5;
	
	p.color.set( ofRandom(255), ofRandom(255), ofRandom(255) );
	planets.push_back(p);
	
}

//--------------------------------------------------------------
void orbitApp::keyReleased(int key){

}

//--------------------------------------------------------------
void orbitApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void orbitApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void orbitApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void orbitApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void orbitApp::windowResized(int w, int h){

}

