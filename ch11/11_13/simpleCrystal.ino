#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

void setup()
{
    lcd.print("I'm in an LCD!");
}

void loop() {}