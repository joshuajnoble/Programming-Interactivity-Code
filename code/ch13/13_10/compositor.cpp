#include "compositor.h"

void compositor::setup(){

	shader.load("videoCompositor.vert", "videoCompositor.frag");	
	background.loadImage("screen.png");

	grab.setDeviceID(4);
	grab.initGrabber(320, 240);
	grab.setUseTexture(true);
	
}

void compositor::update(){
	grab.grabFrame();
}

void compositor::draw(){
	
	ofBackground(255, 255, 255);
	shader.begin();

	shader.setUniformTexture("video", grab, 0);
	shader.setUniformTexture("background", background, 1);
	shader.setUniform1f("greenAmt", (float) mouseX / ofGetWidth());
    shader.setUniform1f("redAmt", (float) mouseY / ofGetHeight());
	
	ofPushMatrix();
	
	ofTranslate(200, 200, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex2f(0, 0);
	glTexCoord2f(320, 0);glVertex2f(640, 0);
	glTexCoord2f(320, 240);glVertex2f(640, 480);
	glTexCoord2f(0, 240);glVertex2f(0, 480);
	glEnd();
	
	ofPopMatrix();
	
	shader.end();

}

void compositor::mouseMoved(int x, int y){
	
}

