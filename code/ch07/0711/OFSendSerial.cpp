#include "OFSendSerial.h"

void OFSendSerial::setup(){
    serial.setup("/dev/tty.usbserial-A6004920", 19200);

}

void OFSendSerial::keyPressed  (int key){
    serial.writeByte(key);
}