
#include "ofPixelator.h"

void ofPixelator::setup(){
	image.loadImage( "hello.png" );
    modImage.allocate(image.getWidth(), image.getHeight(), OF_IMAGE_COLOR);
	modImage.getPixelsRef() = image.getPixelsRef();
	modImage.update();
}

void ofPixelator::update() {
}

void ofPixelator::draw(){
	//image.draw(50, 50);
	modImage.draw(500, 50);
}



void ofPixelator::keyPressed( int key ) {
	
    
	switch (key) {
		case 115: // s
			modImage.getPixelsRef().swapRgb();
			break;
			
		case 114: // r
        {
            ofPixels p;
            p = modImage.getPixelsRef();
            p.rotate90(1);
			modImage.resize(modImage.getHeight(), modImage.getWidth());
            modImage.getPixelsRef() = p;
			break;
		}	
		case 109: // m
			modImage.getPixelsRef().mirror(true, true);
			break;
		case 113: //p
		{
			ofColor cl(255, 255, 0);
			modImage.getPixelsRef().setColor(mouseX - 500, mouseY - 50, cl);
			break;
		}
		case 122: //z
			modImage.getPixelsRef().resize(200, 200);
			break;
		case 99: //c
			modImage.getPixelsRef() = image.getPixelsRef();
			break;
		default:
			break;
	}
	
	modImage.update();
	
}