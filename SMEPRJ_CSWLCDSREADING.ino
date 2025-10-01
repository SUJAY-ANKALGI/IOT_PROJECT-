#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

double Voltage = 0;
double Current = 0;
double ZeroPoint = 2.5; // will be calibrated at startup

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Calibrating...");
  
  // Auto-calibration (average over 2000 samples)
  double sum = 0;
  for (int i = 0; i < 2000; i++) {
    sum += (5.0 / 1024.0) * analogRead(A0);
    delay(1);
  }
  ZeroPoint = sum / 2000.0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ZeroPoint=");
  lcd.print(ZeroPoint, 2); // show calibrated offset
  delay(2000);
  lcd.clear();
}

void loop() {
  Voltage = 0;

  // Take 1000 samples for precision
  for (int i = 0; i < 1000; i++) {
    Voltage += (5.0 / 1024.0) * analogRead(A0);
    delay(1);
  }
  Voltage = Voltage / 1000.0;

  // Calculate current using calibrated ZeroPoint
  // Change 0.100 for 20A sensor, 0.185 for 5A, 0.066 for 30A
  Current = (Voltage - ZeroPoint) / 0.100;

  // Print to Serial
  Serial.print("Voltage Sensed (V) = ");
  Serial.print(Voltage, 2);
  Serial.print("\t Current (A) = ");
  Serial.println(Current, 2);

  // Print to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage:");
  lcd.print(Voltage, 2);
  lcd.print("V");

  lcd.setCursor(0, 1);
  lcd.print("Current:");
  lcd.print(Current, 2);
  lcd.print("A");

  delay(1000);
}
