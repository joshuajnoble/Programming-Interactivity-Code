
#include <MotorShield.h>

const int HALL_PINL = 1;
const int HALL_PINR = 2;

// this will depend on your sensors && setup
// but for the allegro A1321, we start at 2.5V or
// 512 on the analogRead
const int THRESHOLD = 0;

bool isStopped = true;
Motor dc(2, 48);

void setup() {
}

void loop() {
  int hallPosL = analogRead(HALL_PINR);
  int hallPosR = analogRead(HALL_PINL);
  
  if(hallPosL > THRESHOLD)
  {
    dc.run( FORWARD );
    dc.setSpeed( 255 - (hallPosL/2));
    isStopped = true;
  }
  else if(hallPosR > THRESHOLD)
  {
    dc.run( BACKWARD );
    dc.setSpeed( 255 - (hallPosR/2) );
    isStopped = true;
  }
  else {
    if(!isStopped) {
      dc.run( RELEASE );
      isStopped = true;
    }
  }
}
