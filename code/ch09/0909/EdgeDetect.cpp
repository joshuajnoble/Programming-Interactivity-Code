#include "EdgeDetect.h"

void EdgeDetect::setup(){
	
	sobelHorizontal[0][0] = -1; sobelHorizontal[0][1] = 0; sobelHorizontal[0][2]= 1;
    sobelHorizontal[1][0] = -2; sobelHorizontal[1][1] = 0; sobelHorizontal[1][2] = 2;
    sobelHorizontal[2][0] = -1; sobelHorizontal[2][1]= 0; sobelHorizontal[2][2] = 1;
	
    sobelVertical[0][0] = 1; sobelVertical[0][1] = 2; sobelVertical[0][2]= 1;
    sobelVertical[1][0] = 0; sobelVertical[1][1] = 0; sobelVertical[1][2] = 0;
    sobelVertical[2][0] = -1; sobelVertical[2][1]= -2; sobelVertical[2][2] = -1;

	prewittHorizontal[0][0] = 1; prewittHorizontal[0][1] = 1; prewittHorizontal[0][2]= 1;
    prewittHorizontal[1][0] = 0; prewittHorizontal[1][1] = 0; prewittHorizontal[1][2] = 0;
    prewittHorizontal[2][0] = -1; prewittHorizontal[2][1] = -1; prewittHorizontal[2][2] = -1;
	
    prewittVertical[0][0] = 1; prewittVertical[0][1] = 0; prewittVertical[0][2]= -1;
    prewittVertical[1][0] = 1; prewittVertical[1][1] = 0; prewittVertical[1][2] = -1;
    prewittVertical[2][0] = 1; prewittVertical[2][1] = 0; prewittVertical[2][2] = -1;

	imagePath = "http://programminginteractivity.com/hello.jpg"; // there's also a hello.bmp to test 1 channel
	
	img.loadImage(imagePath);
	
    // set aside memory for the image
    edgeDetectedData = new unsigned char[img.width * img.height * 3];
	
    updateImg = true;
	dwThreshold = 100;
}

void EdgeDetect::update(){
    ofBackground(255, 255, 255);
    if(updateImg) {
		if(img.getPixelsRef().getNumChannels() == 3) {
			edgeDetect3Channel();
		} else { 
			edgeDetect1Channel();
		}
        updateImg = false;
    }
}

void EdgeDetect::draw(){
    img.draw(0, 0);
    newImg.draw(img.width, 0);
}

void EdgeDetect::edgeDetect1Channel() {
	int xPx, yPx, i, j, sum, sumY, sumX = 0;
	
	unsigned char* originalImageData = img.getPixels();
	
	int heightVal = img.getHeight();
	int widthVal = img.getWidth();
	
	for(yPx=0; yPx < heightVal; yPx++)  {
		for(xPx=0; xPx < widthVal; xPx++)  {
			sumX = 0;
			sumY = 0;
			if( yPx == 0) {
				sum = 0;
			} else if( xPx == 0) {
				sum = 0;
			} else   { // Convolution starts here
				           for(i=-1; i<=1; i++)  {
							for(j=-1; j<=1; j++)  {
								sumX = sumX + (int) originalImageData [(yPx + j) *
																	   img.width + xPx + i] *
								sobelHorizontal[i + 1][j + 1];
							}
						}
				for(i=-1; i<=1; i++)  {
                    for(j=-1; j<=1; j++)  {
                        sumY = sumY + (int) originalImageData[(yPx + j) *
															  img.width + xPx + i] *
						sobelVertical[i + 1][j + 1];
					}
                }
                // add them up
                sum = abs(sumX) + abs(sumY);
            }
			
			if(sum>255) sum=255;
            if(sum<210) sum=0;        
			edgeDetectedData[ yPx * img.width + xPx ] = 255 - (unsigned char)(sum);
        }
	}
	
	newImg.setFromPixels(edgeDetectedData, img.width, img.height, OF_IMAGE_GRAYSCALE, false);
}


void EdgeDetect::edgeDetect3Channel() {
	
    unsigned char* imgPixels = img.getPixels();
    unsigned int x,y,nWidth,nHeight;
    int firstPix, secondPix;
	
	nWidth = img.width;
	nHeight = img.height;
	
	int dwStride = (nWidth * (24 / 8) + 3) & ~3;
	long dwOffset = dwStride - nWidth * 3;
	
	int horizLength = (nWidth * 3);
    long horizOffset = horizLength - nWidth * 3;
	
    nHeight = img.height- 2;
    nWidth  = img.width - 2;
	
	for( y = 0; y < nHeight;++y) {
        for( x = 0 ; x < nWidth; ++x) {
			long above = (x*3) + (y*horizLength);
            long center = above + horizLength;
            long below = center + horizLength;
			
			//cout << above << " " << center << " " << below << endl;
			
			firstPix = setPixel(imgPixels, 2, above, center, below, prewittHorizontal);
			secondPix = setPixel(imgPixels, 2, above, center, below, prewittVertical);
			edgeDetectedData[5 + center] = max(dwThreshold, min( (int)sqrt(pow(firstPix,2.f)+pow(secondPix,2.f)), 255 ));
			
			firstPix = setPixel(imgPixels, 1, above, center, below, prewittHorizontal);
			secondPix = setPixel(imgPixels, 1, above, center, below, prewittVertical);
			edgeDetectedData[4 + center] = max(dwThreshold, min( (int) sqrt(pow(firstPix,2.f)+pow(secondPix,2.f)), 255 ));
			
			firstPix = setPixel(imgPixels, 1, above, center, below, prewittHorizontal);
			secondPix = setPixel(imgPixels, 1, above, center, below, prewittVertical);
			edgeDetectedData[3 + center] = max(dwThreshold, min( (int) sqrt(pow(firstPix,2.f) + pow(secondPix,2.f)), 255 ));
			
        }
    }
	newImg.setFromPixels(edgeDetectedData, img.width, img.height, OF_IMAGE_COLOR, true);
}

int EdgeDetect::setPixel(unsigned char* px, int startPixel, int above, int center, int below, const int matrix[3][3]) {
    return (
			(px[startPixel + above] * matrix[0][0]) + 
			(px[startPixel + 3 + above] * matrix[0][1]) + 
			(px[startPixel + 6 + above] * matrix[0][2]) +
            (px[startPixel + center] * matrix[1][0])+ 
			(px[startPixel + 3 + center ] * matrix[1][1]) + 
			(px[startPixel + 6 +center] * matrix[1][2]) + 
			(px[startPixel + below]* matrix[2][0]) + 
			(px[startPixel + 3 + below]* matrix[2][1]) + 
			(px[startPixel + 6 + below]* matrix[2][2]));
}

void EdgeDetect::keyPressed(int key) {
	if(key == '+')
		dwThreshold += 10;
	
	if(key == '-')
		dwThreshold -= 10;
	
	updateImg = true;
}