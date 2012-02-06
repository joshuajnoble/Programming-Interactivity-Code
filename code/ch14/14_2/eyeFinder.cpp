#include "eyeFinder.h"

//--------------------------------------------------------------
void eyeFinder::setup(){

	faceFinder.setup("haarcascade_frontalface_default.xml");
	eyeFinder.setup("haarcascade_eye.xml");
	
    grab.setVerbose(true);
    grab.initGrabber(320,240);
}

//--------------------------------------------------------------
void eyeFinder::update(){
	
	grab.grabFrame();
	
	if(grab.isFrameNew())
	{
		img.setFromPixels(grab.getPixelsRef());
		faceFinder.findHaarObjects(img);
		
		for(int i = 0; i < faceFinder.blobs.size(); i++) {
			ofRectangle cur = faceFinder.blobs[i].boundingRect;
			origin.x = cur.x;
			origin.y = cur.y;
			faceImg.cropFrom(img, cur.x, cur.y, cur.width, cur.height);
			eyeFinder.findHaarObjects(faceImg);
		}
		
	}
}

//--------------------------------------------------------------
void eyeFinder::draw(){
	img.draw(0, 0);
	ofNoFill();
	for(int i = 0; i < eyeFinder.blobs.size(); i++) {
		ofRectangle cur = eyeFinder.blobs[i].boundingRect;
		ofRect(cur.x + origin.x, cur.y + origin.y, cur.width, cur.height);
	}
}

//--------------------------------------------------------------
void eyeFinder::keyPressed(int key){

}

//--------------------------------------------------------------
void eyeFinder::keyReleased(int key){

}

//--------------------------------------------------------------
void eyeFinder::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void eyeFinder::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void eyeFinder::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void eyeFinder::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void eyeFinder::windowResized(int w, int h){

}

//--------------------------------------------------------------
void eyeFinder::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void eyeFinder::dragEvent(ofDragInfo dragInfo){ 

}