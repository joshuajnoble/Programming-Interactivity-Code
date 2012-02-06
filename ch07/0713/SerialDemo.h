#pragma once

#define NUM_BYTES 2

class SerialDemo : public ofBaseApp {
    public:
        void setup();
        void update();
		void draw();
	
		bool bSendSerialMessage;    // a flag for sending serial

		// this will be used to count the number of frames
        // that have passed since the last time the app reads from the serial port
        int countCycles;
        ofSerial serial;
	
};