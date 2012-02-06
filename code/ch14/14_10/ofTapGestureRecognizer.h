//
//  ofTapGestureRecognizer.h
//  xmlSettingsExample
//
//  Created by base on 30/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>  


@interface ofTapGestureRecognizer : NSObject {
	UITapGestureRecognizer *tapGestureRecognizer;  
}  

-(id)initWithView:(UIView*)view;  
-(void)handleTap:(UITapGestureRecognizer *) gr;  

@end
