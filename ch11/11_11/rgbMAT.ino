#include <SPI.h>

//Define the "Normal" Colors
#define BLACK  0
#define RED  0xE0
#define GREEN  0x1C
#define BLUE  0x03
#define ORANGE  RED|GREEN
#define MAGENTA  RED|BLUE
#define TEAL  BLUE|GREEN
#define WHITE (RED|GREEN|BLUE)-0xA0

const int SELECT = 9;

char LEDS[64];
char colors[8] = { BLACK, GREEN, TEAL, BLUE, 
  MAGENTA, RED, ORANGE, WHITE };

void setup()
{
  pinMode(SELECT, OUTPUT);
  SPI.begin();
  
  
  for(int x = 0; x<64; x++) {
      LEDS[x] = colors[ dist(x/8, x%8, 8, 8)];
  }
}

void loop()
{
  digitalWrite(OUTPUT, LOW);
   for(int x = 0; x<64; x++) {
      SPI.transfer( LEDS[x] );
   }
  digitalWrite(OUTPUT, HIGH);
}

int dist(int x, int y, int x1, int y1) {
  return (int) sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
}
