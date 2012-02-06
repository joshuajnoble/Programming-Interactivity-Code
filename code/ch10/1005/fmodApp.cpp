#include "fmodApp.h"

void fmodApp::setup(){
	
	keyIsDown = false;
	
	lvelocity.set(1, 1, 1);
	lup.set(0, 1, 0);
	lforward.set(0, 0, 1);
	lposition.set(0, 0, 0);
	
	sposition.set(3, 3, 2);
	svelocity.set(1, 1, 1);
	
   	player.loadSound(ofToDataPath("organ.wav"));
    player.setVolume(0.75);
    player.setMultiPlay(true);
    player.play();  
}

void fmodApp::update() {
    if(!player.getIsPlaying())
        player.play();
	
	
	if ( keyIsDown )
		settingListener = false;
	else
		settingListener = true;
	
	
	player.updateListener(lposition, lvelocity, lforward, lup);
	player.updateSound(sposition, svelocity);
	player.update();
}

void fmodApp::draw(){
    ofSetHexColor(0xff0000);
    ofEllipse(sposition.x*20, sposition.y*20, 10, 10);
    ofSetHexColor(0x0000ff);
    ofEllipse(lposition.x*20, lposition.y*20, 10, 10);
}

void fmodApp::mouseDragged( int x, int y, int button ) {
    if(settingListener) {
        sposition.x = float(x)/20;
        sposition.y = float(y)/20;
    } else {
        lposition.x= float(x)/20;
        lposition.y = float(y)/20;
    }
}

void fmodApp::keyPressed( int key ){
	keyIsDown = true;
}

void fmodApp::keyReleased( int key ) {
	keyIsDown = false;
}