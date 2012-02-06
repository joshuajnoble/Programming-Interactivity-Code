/*
 *  NetworkCamClient.cpp
 *  emptyExample
 *
 *  Created by base on 10/09/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#include "NetworkCamClient.h"

void NetworkCamClient ::setup(){
    ofBackground(60,60,70);
	tex.allocate(320, 240, GL_RGB);
    pixelsLoaded = false;
}

void NetworkCamClient::update(){
    client.update(2048);
	
    if( client.getState() == COMPLETE ){
        tex.loadData(client.pixels, 320, 240, GL_RGB);
        pixelsLoaded = true;
    }
}

void NetworkCamClient::draw(){
	
    string statusStr =  "status: " + client.getStateStr();
	
    ofSetColor(255, 0, 255);
    ofDrawBitmapString(statusStr, 10, 20);
    ofDrawBitmapString("client - launch server than hit c key to connect - r to reset the state", 10, ofGetHeight()-20);
	
    ofSetColor(255, 255, 255);
	if( pixelsLoaded ){
        tex.draw(0, 25);
    }
}

void NetworkCamClient::keyPressed  (int key){
    if( key == 'c'){
        client.setup("127.0.0.1", 44999);
    }
    if(key == 'r'){
        client.reset();
    }
}