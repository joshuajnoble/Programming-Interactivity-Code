#include "textureDemo.h"

void textureDemo::setup(){
	
    w = 500;
    h = 500;
    colorTexture.allocate( w, h, GL_RGB );
    colorPixels.allocate( w, h, 3 );
	
    // color pixels, use w and h to control red and green
	ofColor col;
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            col.set( i, j, 0 );
			colorPixels.setColor( j, i, col );
        }
    }
    // this is important, we load the data into the texture,
    // preparing it to be used by the OpenGL renderer
    colorTexture.loadData(colorPixels);
	
	countUp = true;
}


void textureDemo::update(){
	if( countUp ) {
		blue += 0.1;
	} else {
		blue -= 0.1;
	}
	
	if( blue > 254. || blue < 0.f ) 
		countUp = !countUp;
}

void textureDemo::draw(){
    ofBackground(255,255,255);
	colorTexture.draw(0, 0, mouseX, mouseY);
}

void textureDemo::mouseMoved(int x, int y ){
	
	ofColor col;
    // when the mouse moves, we change the color image:
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
			col.set( i/2, j/2, blue );
			colorPixels.setColor( j, i, col );
        }
    }
    // finally, load those pixels into the texture
    colorTexture.loadData(colorPixels );
}