/*
 *  NetworkCamClient.cpp
 *  emptyExample
 *
 *  Created by base on 10/09/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "networkCamServer.h"

void networkCamServer::setup(){
    ofBackground(20,20,20);
    server.setup(44999);
    grabber.initGrabber(320, 240, true);
}

void networkCamServer::update(){
    server.update(2048);
    grabber.grabFrame(); // grab a frame form the video
}

void networkCamServer::draw(){
    grabber.draw(0, 25);
}

void networkCamServer::keyPressed  (int key){
    if( key == ' '){
        unsigned char * pix = grabber.getPixels();
        server.sendPixels(pix);
    }
}