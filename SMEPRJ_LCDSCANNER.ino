#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F depending on your module
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();            // Initialize the LCD
  lcd.backlight();       // Turn on the backlight
  lcd.setCursor(0, 0);   // Set cursor to column 0, row 0
  lcd.print("Hello, World!"); // Print message
}

void loop() {
  // Nothing here, text stays on screen
}
