#pragma mark once

#include "ofMain.h"

class OFSendSerial : public ofBaseApp{

    public:
        void setup();
        void keyPressed(int key);
        ofSerial serial; // here's our ofSerial object that we'll use
};
