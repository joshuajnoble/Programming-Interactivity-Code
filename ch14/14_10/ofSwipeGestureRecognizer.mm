
#import "ofSwipeGestureRecognizer.h"


@implementation ofSwipeGestureRecognizer


-(id)initWithView:(UIView*)view{  
    if((self = [super init])){  
        swipeGestureRecognizer = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(handleGesture:)];  
        [view addGestureRecognizer:swipeGestureRecognizer];  
    }  
    return self;  
}  

-(void)handleGesture:(UISwipeGestureRecognizer *) gr{  
    if([gr state] == UIGestureRecognizerStateRecognized){  
        NSLog(@"swipe!");  
    }  
}  

-(void)dealloc{  
    [swipeGestureRecognizer release];  
    [super dealloc];  
}  

@end
