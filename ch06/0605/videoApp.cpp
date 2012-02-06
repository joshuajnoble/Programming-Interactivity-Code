#include "videoApp.h"

void videoApp::setup()
{
    ofBackground(255,255,255);
    screenHeight = float(ofGetScreenHeight());
	//player.loadMovie("a_movie2.mpeg");// this loads from the data folder
    player.loadMovie("http://programminginteractivity.com/fingers.mov"); // this loads from a website
    player.play();
    player.play();
    isPaused = false;
}

void videoApp::update()
{
    player.idleMovie();
}

void videoApp::draw()
{
    player.draw(20, 20);
}

void videoApp::mouseMoved( int x, int y )
{
    float yPos = (mouseY / screenHeight ) * 2.0;
    player.setSpeed(yPos);
}

void videoApp::keyPressed  (int key)  {
    if(    isPaused ) {
        isPaused = false;
    } else {
        isPaused = true;
    }
    player.setPaused(isPaused);
}