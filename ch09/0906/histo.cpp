#include "histo.h"

void histo::setup(){
	
    img.loadImage("hello.png");
	
    for(int i = 0; i < 2048; i++) {
        pxColors[i] = 0;
    }
	
    ofPixels pix = img.getPixelsRef();
#ifndef USE_OFCOLOR	
	if(pix.getNumChannels() == 3) { // slightly faster, but less accurate
		for (int i = 0; i < pix.getWidth() * pix.getHeight() * 3; i+=3) {
			int color = (pix[i] << 16 | pix[i+1] << 8 | pix[i+2]);
			pxColors[ color / 8096 ] += 1;
		}
		
	} else if (pix.getNumChannels() == 4) {
		for (int i = 0; i < pix.getWidth() * pix.getHeight() * 4; i+=4) {
			int color = (pix[i] << 16 | pix[i+1] << 8 | pix[i+2]);
			pxColors[ color / 8096 ] += 1;
		}
	}
#endif	
#ifdef USE_OFCOLOR
	for (int i = 0; i < pix.getWidth(); i++) {
		for(int j = 0; j < pix.getHeight(); j++) {
			ofColor color = pix.getColor(i, j);
			pxColors[ int (color.getHue() * 8.0) ] += 1;
		}
	}
#endif
}

void histo::update(){ }


void histo::draw(){

	ofBackground(255, 255, 255);

#ifndef USE_OFCOLOR	
	for(int i = 0; i < 2048; i++) {
		int il = i * 8096;
		int r = (il & 0xFF0000) >> 16;
		int g = (il & 0xFF00) >> 8;
		int b = il & 0xFF;
		ofSetColor(r, g, b);
		ofLine( i/2, 0, i/2,  pxColors[i] / 4 );
	} 
#endif	
#ifdef USE_OFCOLOR
	ofColor cl;
	cl.setHsb(255, 255, 255, 255);
	for(int i = 0; i < 2048; i++) {
		float ind = ofClamp((float) i / 8.f, 0.f, 255.f);
		cl.setHsb( ind, 255, 255, 255);
		ofSetColor(cl);
		ofLine( i/2, 0, i/2,  pxColors[i] / 8 );
	}
#endif
}
