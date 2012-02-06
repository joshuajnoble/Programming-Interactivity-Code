#pragma mark once
#include "ofMain.h"


class EdgeDetect : public ofBaseApp{
	
public:
	
	void setup();
	void update();
	void draw();
	int setPixel(unsigned char* px, int startPixel, int dep,
				 int depthOfNextLine, int depthOfNextNextLine,
				 const int matrix[3][3]);
	
	void edgeDetect1Channel(); // this is for grayscale images,
	// with only gray pixels
	void edgeDetect3Channel(); // this is for color images with an RGB
	
	void keyPressed(int key);
	
	int sobelHorizontal[3][3]; // here's the sobel kernel
	int sobelVertical[3][3];
	
	int prewittHorizontal[3][3]; // here's the prewitt kernel
	int prewittVertical[3][3];
	
	unsigned char* edgeDetectedData;
	ofImage img;
	ofImage newImg;
	
	int dwThreshold;
	bool updateImg;
	
	string imagePath;
	
};

