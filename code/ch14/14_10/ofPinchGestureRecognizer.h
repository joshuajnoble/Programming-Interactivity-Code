//
//  ofPinchGestureRecognizer.h
//  xmlSettingsExample
//
//  Created by base on 30/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>  
#include "ofPinchEvent.h"
#include "ofMain.h"

ofEvent<ofPinchEventArgs> ofPinchEvent;

@interface ofPinchGestureRecognizer : NSObject {

	UIPinchGestureRecognizer *pinchGestureRecognizer;  
}

-(id)initWithView:(UIView*)view; 
- (void)handleGesture:(UIPinchGestureRecognizer *)gestureRecognizer;

@end
