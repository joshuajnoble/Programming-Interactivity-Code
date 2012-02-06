//
//  ofTapGestureRecognizer.m
//  xmlSettingsExample
//
//  Created by base on 30/09/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "ofTapGestureRecognizer.h"


@implementation ofTapGestureRecognizer


-(id)initWithView:(UIView*)view{  
    if((self = [super init])){  
        tapGestureRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTap:)];  
        [view addGestureRecognizer:tapGestureRecognizer];  
    }  
    return self;  
}  

-(void)handleTap:(UITapGestureRecognizer *) gr{  
    if([gr state] == UIGestureRecognizerStateRecognized){  
        NSLog(@"tap!");  
    }  
}  

-(void)dealloc{  
    [tapGestureRecognizer release];  
    [super dealloc];  
}  

@end
