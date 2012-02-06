#include "MouseCircleFollow.h"

void MouseCircleFollow::setup(){

    ofSetWindowShape(700,700);
    max_distance = dist(0, 0, 700, 700);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    int i;
	for(i = 0; i<numOfCircles; i++) {
        xPos[i] = ofRandomf() * 700;
        yPos[i] = ofRandomf() * 700;
    }

}

void MouseCircleFollow::update(){
    int i, j;

    float modifier;
    for(i = 0; i<numOfCircles; i++)
    {
        if(mouseX > xPos[i]) {
            xPos[i] += createRandomizedNewPos(xPos[i], mouseX);
        } else {
            xPos[i] -= createRandomizedNewPos(xPos[i], mouseX);
        }

        if(mouseY > yPos[i]) {
            yPos[i] += createRandomizedNewPos(yPos[i], mouseY);
        } else {
            yPos[i] -= createRandomizedNewPos(yPos[i], mouseY);
        }
    }
}

void MouseCircleFollow::draw(){
    int i;
    ofSetColor(255,255,255, 100);
    for(i = 0; i<numOfCircles; i++) {
        ofEllipse(xPos[i],yPos[i],20,20);
    }
}

float MouseCircleFollow::createRandomizedNewPos(float in, float mouse)
{
    return ofRandomf()/2 * tanhl(sqrt((mouse - in)*(mouse - in)))+0.05;
}

float MouseCircleFollow::dist(int startX, int startY, int endX, int endY)
{
    return sqrt((endX-startX)*(endX-startX) + (endY-startY)*(endY-startY));
}