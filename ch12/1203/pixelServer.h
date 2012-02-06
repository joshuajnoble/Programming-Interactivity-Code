#pragma mark once

#include "ofxNetwork.h"
#include "ofMain.h"

const int NUM_BYTES_IN_IMG = (320 * 240 * 3);

enum serverState{
    NONE, READY, SENDING, COMPLETE
};


class pixelServer{
public:

	serverState state;
	int numSentBytes;
	int totalBytes;
	ofxTCPServer TCP;
	unsigned char pixels[NUM_BYTES_IN_IMG];
	
    pixelServer(){
        state        = NONE;
        totalBytes    = NUM_BYTES_IN_IMG;
    }
	
	
    void setup(int port = 11999){
		//setup the server to listen on 11999
		TCP.setup(port);
		state = READY;
    }
	
    void sendPixels(unsigned char * pixelData) {
        if( state == NONE ) return;
		memcpy(pixels, pixelData, totalBytes);
        state = SENDING;
        numSentBytes    = 0;
    }
	
    void update(int numToSend = 1024){
        if( state == SENDING && numSentBytes < totalBytes ){
            if( numToSend + numSentBytes > totalBytes ){
                numToSend -= ( (numToSend + numSentBytes) - totalBytes );
            }
            TCP.sendRawBytesToAll( (char *)&pixels[numSentBytes], numToSend);
            numSentBytes += numToSend;
        }
		
        if( numSentBytes >= totalBytes ){
            state = COMPLETE;
        }
    }
};
