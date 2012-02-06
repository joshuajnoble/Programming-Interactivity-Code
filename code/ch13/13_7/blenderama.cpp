
#include "blenderama.h"

const int BLENDS[] = { GL_ZERO, GL_ONE, GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR, GL_DST_COLOR, GL_ONE_MINUS_DST_COLOR, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_SRC_ALPHA_SATURATE, GL_CONSTANT_COLOR, GL_ONE_MINUS_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA };
	

void blenderama::setup(){
	
	//ofDisableArbTex();
	ofEnableNormalizedTexCoords();
	
    img.loadImage("ofpic.png");
    text.allocate(128, 128, GL_RGBA, true);
    ang = 0;
	glEnable(GL_DEPTH_TEST); // enable depth testing, otherwise things will
	//look really werid
    glDepthFunc(GL_LEQUAL);    // set the type of depth testing
    text.loadData(img.getPixels(), 128, 128, GL_RGBA);
	
	currentLBlend = 6;
	currentRBlend = 7;
	

	for (int i = 0; i < numCubes; i++){
        cubePos[i].set(ofRandom(200.0, 600.0), ofRandom(200.0, 600.0), ofRandom(200.0, 600.0));
    }
}


void blenderama::update(){
	//used to rotate the view
    ang+=0.1;
}

void blenderama::draw() {
	
	glEnable(GL_BLEND);
	text.bind();
	glBlendFunc( BLENDS[currentLBlend], BLENDS[currentRBlend] );
	
    for (int i = 0; i < numCubes; i++) {
		ofPushMatrix();
		ofTranslate(cubePos[i]);
        ofBox(50);
		ofPopMatrix();
    }

    glDisable(GL_BLEND);
	text.unbind();
	glDisable(GL_BLEND);
	
}

void blenderama::keyPressed  (int key){
    switch( key ){
		case 'a':
			if(currentLBlend > 13)
				currentLBlend = 0;
			else
				currentLBlend++;
			break;
		case 's':
			if(currentLBlend < 0)
				currentLBlend = 13;
			else
				currentLBlend--;
			break;
		case 'd':
			if(currentRBlend > 13)
				currentRBlend = 0;
			else
				currentRBlend++;
			break;
		case 'f':
			if(currentRBlend < 0)
				currentRBlend = 13;
			else
				currentRBlend--;
			break;
	}
}
