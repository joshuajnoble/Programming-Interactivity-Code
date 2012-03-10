
#include "MouseVoronoi.h"

void MouseVoronoi::setup() {
	needRedraw = false;
	ofSetBackgroundAuto(false);
}

void MouseVoronoi::update() {}

void MouseVoronoi::draw() {
	
	if (! needRedraw ) return;
	
	ofBackground(255, 255, 255);
	
	float w = ofGetWidth();
	float h = ofGetHeight();
	
	for( int x=0; x<w && (xs.size() > 0); x+=4 ) {
		for( int y=0; y<h; y+=4) {
			int idx = 0;
			float dd;
			dd = ofDist(xs[0],ys[0],x,y);
			for( int i=1; i<d.size(); i++ ) {
				float d0 = ofDist(xs[i],ys[i],x,y);
				if( dd > d0 ) {
					dd = d0;
					idx = i;
				}
			}
			ofSetColor(c[idx]);
			ofRect(x, y, 4, 4);
		}
	}
	ofSetColor(255);
	for( int i=0; i<xs.size(); i++ ) {
		ofEllipse(xs[i],ys[i],10,10);
	}
	
	needRedraw = false;
}

void MouseVoronoi::mousePressed( int x, int y, int button ) {
	xs.push_back(mouseX);
	ys.push_back(mouseY);
	d.push_back(0);
	ofColor cl(ofRandom(255),ofRandom(255),ofRandom(255));
	c.push_back(cl);
	
	needRedraw = true;
}

