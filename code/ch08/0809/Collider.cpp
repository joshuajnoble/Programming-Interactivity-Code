
#include "Collider.h"

void Collider::setup() {
	gravity = ofVec3f(0.0, 5.0f);
	
    balls[0].color[0] = 0;
    balls[1].color[1] = 0;
    balls[2].color[2] = 0;

    //for smooth animation, set vertical sync if we can
    ofSetVerticalSync(true);
    // also, frame rate:
    ofSetFrameRate(60);
}

void Collider::update(){
	
	for(int i=0; i<count; i++) {
		balls[i].addForce(gravity);
		balls[i].updateBall();
	}
	
	checkCollision();
	
}

void Collider::draw(){
	
	for(int i=0; i<count; i++) {
		balls[i].drawFrame();
	}
	
    drawConnectors();
	
	ofSetColor(255, 0, 0);
	ofSetLineWidth(2);
	
	float midx = ofGetWidth()/2;
	float midy = ofGetHeight()/2;
	ofLine(midx, midy, midx + (gravity.x * 200.f), midy + (gravity.y * 200.f));
}


void Collider::mouseMoved(int x, int y ){
	gravity.set(float(x)/ofGetWidth() - 0.5, (float)y/ofGetHeight() - 0.5);
}

void Collider::drawConnectors() {
	
	ofSetColor(0, 0, 0);
	ofSetLineWidth(1);
    int i, j;
    for(i=0; i<count; i++)
    {
        for(j=i+1; j<count; j++) {
            ofLine(balls[i].location.x, balls[i].location.y, balls[j].location.x, balls[j].location.y);
        }
    }
}

void Collider::checkCollision()
{
    int i, j;
    for(i=0; i<numBalls; i++) {
        for(j=i+1; j<numBalls; j++) {
            if(ofDist(balls[i].location.x, balls[i].location.y, balls[j].location.x, balls[j].location.y) < 100) {
				balls[i].collision( balls[j] );
            }
        }
    }
}