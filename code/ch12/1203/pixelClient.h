#include "ofxNetwork.h"
#include "ofMain.h"

const int NUM_BYTES_IN_IMG = (320 * 240 * 3);

enum clientState{
    NONE, READY, RECEIVING, COMPLETE
};

class pixelClient{
public:
	pixelClient(){
        state = NONE;
        totalBytes = NUM_BYTES_IN_IMG;
        bytesRecieved = 0;
        memset(pixels, 255, totalBytes);
    }
	
    int getState(){
        return state;
    }
	
    string getStateStr(){
        if(state == NONE) { return "NONE"; }
        else if(state == READY) { return "READY"; }
        else if(state == RECEIVING) { return "RECEIVING"; }
        else if(state == COMPLETE) { return "COMPLETE"; }
        else { return "ERR"; }
    }
	
    void reset(){
        state = READY;
        bytesRecieved = 0;
    }
	void setup(string ip, int port = 11999){
		TCP.setup(ip, port);
		state = READY;
		bytesRecieved = 0;
    }
	
	void update(int bytesToGet = 2048){
		
        if( state == READY || state == RECEIVING ){
            if( bytesToGet + bytesRecieved >= NUM_BYTES_IN_IMG ){
                bytesToGet -= ( ( bytesToGet + bytesRecieved ) -
							   NUM_BYTES_IN_IMG );
            }
			
            char tmpBuffer[bytesToGet];
            int numRecieved = TCP.receiveRawBytes(tmpBuffer, bytesToGet);
			
            if( numRecieved > 0 ){
                state = RECEIVING;
                memcpy(&pixels[bytesRecieved],tmpBuffer, numRecieved);
                bytesRecieved += numRecieved;
            }
			
            if( bytesRecieved >= NUM_BYTES_IN_IMG ){
                state = COMPLETE;
            }
        }
    }
	
    clientState state;
    int bytesRecieved;
    int totalBytes;
    ofxTCPClient TCP; // the TCP client that handles the actual communication
    unsigned char pixels[NUM_BYTES_IN_IMG];
};