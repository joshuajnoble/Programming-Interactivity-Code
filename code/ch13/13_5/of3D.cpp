
#include "of3D.h"
void of3D::setup()
{

	ofEnableNormalizedTexCoords();
	
	ofImage img;
    img.loadImage("ofpic.png");
	img.mirror(false, true);
    text.allocate(128, 128, GL_RGBA, true);
    ang = 0;
	
	glEnable(GL_DEPTH_TEST); // enable depth testing, otherwise things will
    text.loadData(img.getPixels(), 128, 128, GL_RGBA);
	
}


void of3D::update()
{
    ang += 0.1;
}

void of3D::draw() {
	
	ofBackground(122,122,122);

	text.bind();
	ofTranslate(ofGetWidth() * .5, ofGetHeight() * .5, 0);
	ofRotate(ang, 1.0, 1.0, 1.0);
	ofBox(200);
	text.unbind();
	
}