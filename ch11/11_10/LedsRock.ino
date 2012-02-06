#include "LedControl.h" //  need the library
LedControl control = LedControl(12,11,10,1); // lc is our object

// pin 12 to MAX7219 pin 1
// pin 11 to the CLK pin 13
// pin 10 to LOAD pin 12

int currentColumn = 0;

void setup() {
  
  control.shutdown(0,false);// turn off power saving, enables display
  control.setIntensity(0,8);// sets brightness (0~15 possible values)
  control.clearDisplay(0);// clear screen
  
}

void loop() {
  
  currentColumn++;
  if( currentColumn > 7 ) currentColumn = 0;
  
  for (int row=0; row<8; row++) {
    for (int col=0; col<8; col++) {
      if(col == currentColumn) {
        control.setLed(0,col,row,true); // turns on LED at col, row
      } else {
        control.setLed(0,col,row,false); // turns off LED at col, row
      }
    }
  }
  delay(30);
}
