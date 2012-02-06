
#import <Foundation/Foundation.h> 


@interface ofSwipeGestureRecognizer : NSObject {
	
	UISwipeGestureRecognizer *swipeGestureRecognizer;  
}

-(id)initWithView:(UIView*)view; 
- (void)handleGesture:(UISwipeGestureRecognizer *) gr;

@end
