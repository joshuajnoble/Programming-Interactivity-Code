#pragma mark once

#include "ofMain.h"

class Sound3D : public ofFmodSoundPlayer {
    public:
	
	Sound3D();
	
	static void initializeFmod();
	static void closeFmod();
	bool loadSound(string fileName, bool stream = false);
	void play();
	
	FMOD_VECTOR listenerVelocity, listenerUp, listenerForward, listenerPos, soundPosition, soundVelocity;
	
	void updateListener(ofVec3f position, ofVec3f velocity, ofVec3f forward, ofVec3f up);
	void updateSound( ofVec3f position, ofVec3f velocity );
	void update();
	
};
