#include "OFTilter.h"


void OFTilter::setup(){

    countCycles = 0; // start our count at 0
    bSendSerialMessage = true; // send a message right away
    // serial.enumerateDevices(); // uncomment this line to see all your devices

    // set this to our COM port, the same one we use in the Arduino IDE
    // the second part is the baud rate of the controller
    serial.setup("/dev/tty.usbserial-A6004920", 19200);
}

void OFTilter::update(){

    if (bSendSerialMessage){
        // send a message to the Arduino controller telling it that we're
        // ready to get accelerometer data
        serial.writeByte('x');

        unsigned char bytesReturned[NUM_BYTES];
        memset(bytesReturned, 0, NUM_BYTES);

        // keep reading bytes, until there's none left to read
        while( serial.readBytes(bytesReturned, NUM_BYTES) &gt; 0){
        };

        // make our integers from the individual bytes
        xVal = bytesReturned[0];
        xVal <<= 8;
        xVal += bytesReturned[1];

        yVal = bytesReturned[2];
        yVal <<= 8;
        yVal += bytesReturned[3];

        zVal = bytesReturned[4];
        zVal <<= 8;
        zVal += bytesReturned[5];

        printf("first  %i %i %i \n", xVal, yVal, zVal);
        // get ready to wait a few frames before asking again
        bSendSerialMessage = false;
    }

    countCycles++;

    if(countCycles == 5) {
        bSendSerialMessage = true;
        countCycles = 0;
    }
}