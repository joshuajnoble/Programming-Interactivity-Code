#include "Sound3D.h"
#include "ofFmodSoundPlayer.cpp"

bool bFmod3DInitialized = false;

Sound3D::Sound3D(){

	listenerVelocity.x = 1;
    listenerVelocity.y = 1;
    listenerVelocity.z = 1;
    listenerUp.x = 0.f;
    listenerUp.y = 1.f;
    listenerUp.z = 0;
    listenerForward.x = 0.f;
    listenerForward.y = 0.f;
    listenerForward.z = 1.0;
    listenerPos.x = 3.f;
    listenerPos.y = 3.f;
    listenerPos.z = 1.f;
    soundPosition.x = 3.f;
    soundPosition.y = 3.f;
    soundPosition.z = 1.0;
    soundVelocity.x = 1;
    soundVelocity.y = 1;
    soundVelocity.z = 1.0;
	
    initializeFmod();
}

// this should only be called once
void Sound3D::initializeFmod(){

    if(!bFmod3DInitialized){
        FMOD_System_Create(&sys);
        FMOD_System_Init(sys, 32, FMOD_INIT_NORMAL, NULL);
        //do we want just 32 channels?
        
		FMOD_System_Set3DSettings(sys, 10.0f, 10.0f, 10.0f);
        FMOD_System_GetMasterChannelGroup(sys, &channelgroup);
        bFmod3DInitialized = true;
    }
	
}

void Sound3D::loadSound(string fileName, bool stream)
{
    result = FMOD_System_CreateSound(sys, ofToDataPath(fileName).c_str(), FMOD_3D, NULL, &sound);
    result = FMOD_Sound_Set3DMinMaxDistance(sound, 1.f, 5000.0f);

    if (result != FMOD_OK){
        bLoadedOk = false;
        printf("ofSoundPlayer: Could not load sound file %s \n", fileName.c_str() );
    } else {
        bLoadedOk = true;
        FMOD_Sound_GetLength(sound, &length, FMOD_TIMEUNIT_PCM);
        isStreaming = stream;
    }
}

void Sound3D::play(){

    FMOD_System_PlaySound(sys, FMOD_CHANNEL_FREE, sound, bPaused, &channel);
    FMOD_VECTOR pos = {  0.0f, 0.0f, 0.0f };
    FMOD_VECTOR vel = {  0.0f, 0.0f, 0.0f };
    FMOD_Channel_Set3DAttributes(channel, &pos, &vel);
    FMOD_Channel_GetFrequency(channel, &internalFreq);
    FMOD_Channel_SetVolume(channel,volume);
}

void Sound3D::updateListener(ofVec3f position, ofVec3f velocity, ofVec3f forward, ofVec3f up)
{
	
	listenerVelocity.x = velocity.x;
	listenerVelocity.y = velocity.y;
	listenerVelocity.z = velocity.z;
	
	listenerPos.x = position.x;
	listenerPos.y = position.y;
	listenerPos.z = position.z;
	
	listenerForward.x = forward.x;
	listenerForward.y = forward.y;
	listenerForward.z = forward.z;
	
	listenerUp.x = up.x;
	listenerUp.y = up.y;
	listenerUp.z = up.z;
	
	FMOD_System_Set3DListenerAttributes(sys, 0, &listenerPos, &listenerVelocity, &listenerForward, &listenerUp);

}

void Sound3D::updateSound( ofVec3f position, ofVec3f velocity )
{
	soundPosition.x = position.x;
    soundPosition.y = position.y;
    soundPosition.z = position.z;
	
    soundVelocity.x = velocity.x;
    soundVelocity.y = velocity.y;
    soundVelocity.z = velocity.z;
	
	FMOD_Channel_Set3DAttributes(channel, &soundPosition, &soundVelocity);
}

void Sound3D::update()
{
	FMOD_System_Update(sys);
}
