#include "boxCV.h"

void boxCV::setup(){

	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(320,240);

    colorImg.allocate(320,240);
	grayImage.allocate(320,240);
	grayBg.allocate(320,240);
	grayDiff.allocate(320,240);
	
	ofSetVerticalSync(true);
	
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.setFPS(30.0);
	
	bodyShape = NULL;
	
	bLearnBakground = true;
	threshold = 80;
	
	debugging = false;
	contours = false;
}

void boxCV::update()
{
	ofBackground(100,100,100);
	float height = ofGetHeight();
	
	vector<ofxBox2dCircle>::iterator cit = circles.begin();
	
	while( cit != circles.end()) 
	{
		if(cit->getPosition().y > height + 100) {
			circles.erase(cit);
		}
		++cit;
	}
	
	if( circles.size() < 50 ) { // > 100 on screen
		ofxBox2dCircle circle;
		circle.setPhysics(1, 0.5, 0.1);
		float pos = ofRandom(1000) + 10;
		circle.setup(box2d.getWorld(), pos, -100, 10);
		circles.push_back(circle); // add a new one
	}
	
	box2d.update();

	vidGrabber.grabFrame();
	bool newFrame = vidGrabber.isFrameNew();

	if (newFrame){

		colorImg.setFromPixels(vidGrabber.getPixels(), 320, 240);
		colorImg.mirror(false, true);

        grayImage = colorImg;
		if (bLearnBakground == true){
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			bLearnBakground = false;
		}
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);
		contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);	// find holes
	}

	checkBlobs();
}

void boxCV::draw(){
	
	ofSetColor(255, 255, 255);
	ofFill();
	
	vector<ofxBox2dCircle>::iterator cit = circles.begin();
	while( cit != circles.end()) {
		//cit->draw();
		ofCircle(cit->getPosition().x, cit->getPosition().y, 10);
		++cit;
	}
	
	ofSetColor(0, 0, 255);
	
	vector<ofxCvBlob>::iterator c_it = contourFinder.blobs.begin();
	
	if(contours) {
		while(c_it != contourFinder.blobs.end() ) {
			c_it->draw();
			++c_it;
		}
	}
	
	if(bodyShape != NULL) {
		bodyShape->draw();
		
		ofSetColor(0, 0, 255);
		ofFill();
		vector <ofPoint>::iterator pit = bodyShape->getVertices().begin();
		while(pit != bodyShape->getVertices().end() )
		{
			ofCircle(pit->x, pit->y, 5);
			++pit;
		}
	}
}

void boxCV::checkBlobs() 
{
	
	contourFinder.findContours(grayDiff, 120, (grayDiff.getWidth()*grayDiff.getHeight())/2, 5, false); // no holes
	
	if(contourFinder.blobs.size() < 1) return;
	
	vector<ofxCvBlob>::iterator c_it = contourFinder.blobs.begin();
	ofxCvBlob largest = contourFinder.blobs[0];
	
	while(c_it != contourFinder.blobs.end() ) {
		if(c_it->area > largest.area) largest = *c_it;
		++c_it;
	}
	
	cout << " largest " <<  largest.area << " " << largest.pts.size() << endl;
	

	if(!debugging)
	{
		if(bodyShape) {
			bodyShape->destroy();
			delete bodyShape;
		}
		
		bodyShape = new ofxBox2dPolygon();
		ofVec2f scaleUp(ofGetWidth()/320, ofGetHeight()/240);
		
		vector <ofPoint>::iterator pit = largest.pts.begin();
		while(pit != largest.pts.end() )
		{
			// triangulatePolygonWithOutline(resampled, outline);??
			bodyShape->addVertex( *pit * scaleUp );
			++pit;
		}
		
		bodyShape->simplify(20);
		bodyShape->create(box2d.getWorld());
		
		cout << " is good shape " << bodyShape->isGoodShape() << " ";
	
	}
	
}

void boxCV::mouseDragged(int x, int y, int button){

	if(debugging) {
		
		if(bodyShape) 
		{
			bodyShape->destroy();
			delete bodyShape;
		}
		bodyShape = new ofxBox2dPolygon();
		
		ofVec2f ul( x - 50.f, y-50.f);
		ofVec2f ur( x + 50.f, y-50.f);
		ofVec2f lr( x + 50.f, y+50.f);
		ofVec2f ll( x - 50.f, y+50.f);
		
		bodyShape->addVertex(ul);
		bodyShape->addVertex(ur);
		bodyShape->addVertex(lr);
		bodyShape->addVertex(ll);
		
		bodyShape->create(box2d.getWorld());
		
	}
}

void boxCV::mousePressed(int x, int y, int button){

	if(debugging) {
		
		if(bodyShape) 
		{
			bodyShape->destroy();
			delete bodyShape;
		}
		bodyShape = new ofxBox2dPolygon();
		
		ofVec2f ul( x - 50.f, y-50.f);
		ofVec2f ur( x + 50.f, y-50.f);
		ofVec2f lr( x + 50.f, y+50.f);
		ofVec2f ll( x - 50.f, y+50.f);
		
		bodyShape->addVertex(ul);
		bodyShape->addVertex(ur);
		bodyShape->addVertex(lr);
		bodyShape->addVertex(ll);
		
		bodyShape->create(box2d.getWorld());
	
	}
}

void boxCV::keyPressed(int key){
	
	switch (key){
		case ' ':
			bLearnBakground = true;
			break;
		case '+':
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case '-':
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
		case 'd':
			debugging = !debugging;
			break;
		case 'c':
			contours = !contours;
			break;
	}
}