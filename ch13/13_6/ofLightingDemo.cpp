
#include "ofLightingDemo.h"

void ofLightingDemo::setup(){
	
	ofEnableNormalizedTexCoords();
	
	ofImage img;
	img.loadImage("ofpic.png");
	img.mirror(false, true);
    text.allocate(128, 128, GL_RGBA, true);
    ang = 0;
	glEnable(GL_DEPTH_TEST); // enable depth testing, otherwise things will look really weird
    text.loadData(img.getPixels(), 128, 128, GL_RGBA);
	
	light1.setPointLight();
	light2.setPointLight();
}


void ofLightingDemo::update()
{
	
    light1.setPosition( cos(ofGetElapsedTimef()) * 200 + 200, 200, sin(ofGetElapsedTimef()) * 200);
	light2.setPosition( cos(ofGetElapsedTimef()) * 200 + 200, sin(ofGetElapsedTimef()) * 200 + 200, 0);
	
	ang+=0.1;
}

void ofLightingDemo::draw() 
{
	//ofBackground(122,122,122);
	ofEnableLighting();
	
	light1.enable();
	light2.enable();
	
	light1.draw();
	light2.draw();
	
	text.bind();
	ofBox(400, 600, 0, 200);
	ofBox(800, 400, -400, 200);
	ofBox(400, 200, 0, 200);
	ofBox(800, 800, -400, 200);
	text.unbind();
	
	ofDisableLighting();
	
}