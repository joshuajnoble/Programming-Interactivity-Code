/*
 *  ofPinchEvent.h
 *  xmlSettingsExample
 *
 *  Created by base on 30/09/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

class ofPinchEventArgs : ofEventArgs {
	
public:
	ofPinchEventArgs(float sc, float vel):scale(sc), velocity(vel) {   
    }  
	
    float scale;    
    float velocity; 
};
