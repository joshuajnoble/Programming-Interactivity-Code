#include "MouseResponseColor.h"

void MouseResponseColor::setup(){

    ofSetWindowShape(700,700);
    max_distance = ofDist(0, 0, 700, 700);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
}

void MouseResponseColor::draw(){
    int i, j;
    int height = ofGetHeight();
    int width = ofGetWidth();

    for(i = 0; i <= height; i += 20) {
        for(j = 0; j <= width; j += 20) {
            float dist_color = getDistance(mouseX, mouseY, i, j);
            dist_color = dist_color/max_distance * 100;
	    ofSetColor(dist_color*5,dist_color*5,dist_color*5, 123);
            ofEllipse(i, j, 20, 20);
        }
    }
}

float MouseResponseColor::getDistance(int startX, int startY, int endX,      int endY)
{
    return sqrt((endX-startX)*(endX-startX) + (endY-startY)*(endY-startY));
}