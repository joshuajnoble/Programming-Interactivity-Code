#include "Charliplexing.h"

int incomingRow, incomingColumn;

void setup() {
  Serial.begin(57600);
}

void loop() {

  for(uint8_t y = 0; y < 9; y++) {
    for(uint8_t x = 3; x < 11; x++) {
      LedSign::Set(x,y,0);
    }
  }

  while(Serial.available() > 0) {
    if(Serial.read() == 'x') {
      incomingRow = Serial.read();
      incomingColumn = Serial.read();
      LedSign::Set(incomingRow, incomingColumn, 1);
    }
  }
}
