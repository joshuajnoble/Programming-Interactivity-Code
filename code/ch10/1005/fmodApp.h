#pragma mark once

#include "ofMain.h"
#include "Sound3D.h"

class fmodApp : public ofBaseApp{
	
public:
	
	void setup();
	void update();
	void draw();
	void keyPressed( int key );
	void keyReleased( int key );
	void mouseDragged( int x, int y, int button );
	Sound3D player;
	
	bool settingListener;
	bool settingSound;
	
	ofVec3f lposition, lvelocity, lforward, lup;
	ofVec3f sposition, svelocity;
	
	bool keyIsDown;
};

