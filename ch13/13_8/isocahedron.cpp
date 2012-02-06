
#include "isocahedron.h"

void isocahedron::setup()
{	
	glEnable(GL_DEPTH_TEST);
	ofColor color(255, 0, 0);
	float hue = 254.f;
	
	for (int i = 0; i<12; ++i)
	{
		mesh.addVertex( ofVec3f( vdata[i][0], vdata[i][1], vdata[i][2] ));
		
		mesh.addColor(color);
		color.setHue( hue );
		hue -= 20.f;
	}
	
	for (int i = 0; i<20; ++i) 
	{
		mesh.addIndex(tindices[i][0]);
		mesh.addIndex(tindices[i][1]);
		mesh.addIndex(tindices[i][2]);
	}
	
}


void isocahedron::update(){

	ang+=0.1;
}

void isocahedron::draw() {
	
	ofBackground(122,122,122);
	
	ofPushMatrix();
    ofTranslate(400, 400, 0);
    ofRotate(ang, 1.0, 1.0, 1.0);

	mesh.drawFaces();
	
	ofPopMatrix();
}