void SerialDemo::setup(){
    bSendSerialMessage = false;
    serial.enumerateDevices(); // this will print all the devices
    // this is set to the port where your device is connected
    serial.setup("/dev/tty.usbserial-A4001JEC", 9600);
}

void SerialDemo::update(){
    if (bSendSerialMessage){
		
        // send a handshake to the Arduino serial
        serial.writeByte('x');
        // make sure there's something to write all the data to
        unsigned char bytesReturned[NUM_BYTES];
        memset(bytesReturned, 0, NUM_BYTES);
		// keep reading bytes, until there's none left to read
        while( serial.readBytes(bytesReturned, NUM_BYTES) > 0){}
		bSendSerialMessage = false;
	}
	// wait a few cycles before asking again
	countCycles++;
	if(countCycles == 5) {
		bSendSerialMessage = true;
		countCycles = 0;
	}
}

void SerialDemo::draw() {
	ofPoint pt(ofGetWidth()/2, ofGetHeight()/2);
	ofDrawBitmapString(bytesReturned, pt);
}