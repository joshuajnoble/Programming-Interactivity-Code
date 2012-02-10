#include "pixelReader.h"

void pixelReader::setup()
{

	drawPixelGrid = false;
	
    pic.loadImage("hello.png");
    fullSize = pic.width * pic.height;
    ofSetWindowShape(pic.width, pic.height);
    pixels = pic.getPixelsRef();
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	
}

void pixelReader::update(){}

void pixelReader::draw() {
    ofSetupScreen();
    pic.draw(0,0);
	
	int mX = mouseX;
	int mY = mouseY;

	if(mX > pixels.getWidth()) mX = pixels.getWidth();
	if(mX > pixels.getHeight()) mX = pixels.getHeight();

	if(drawPixelGrid) {
		for( int i = 0; i < 10; i++) {
			for( int j = 0; j < 10; j++) {
				ofSetColor( pixels.getColor(mX + i - 5, mY + j - 5 ), 200 );
				ofRect( mX + (i * 20 - 100), mY + (j * 20 - 100), 20, 20 );
			}
		}
	} else {
		ofSetColor(pixels.getColor(mX, mY), 200);
		ofCircle(mX, mY, 50);
	}
	ofSetColor(255, 255, 255);
}

void pixelReader::keyPressed(int key) {
	drawPixelGrid = !drawPixelGrid;
}
