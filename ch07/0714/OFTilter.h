#pragma mark once

#include "ofMain.h"

#define NUM_BYTES 6

class OFTilter : public ofBaseApp{

    public:

        void setup();
        void update();
        void draw();

        int xVal;
        int yVal;
        int zVal;

		// a flag for whether to send our 'handshake's
        bool    bSendSerialMessage;
        //data from serial, we will be reading 6 bytes, two bytes for each integer
        unsigned char bytesRead[NUM_BYTES];
        int countCycles; // this is how to keep track of our time
        ofSerial serial; // this is ofSerial object that enables all this
};
