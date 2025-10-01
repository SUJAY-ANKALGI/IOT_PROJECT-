/*
  Arduino ACS712 DC Current Sensing
  Function: Sense the DC Current and Display on the Serial Monitor
  Prepared By: Krishnarajsinh Jadav
  Fixed Version by ChatGPT
*/

double Voltage = 0;
double Current = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Voltage = 0; // reset before averaging

  // Take 1000 samples for precision
  for (int i = 0; i < 1000; i++) {
    Voltage += (5.0 / 1024.0) * analogRead(A0); // convert analog reading to voltage
    delay(1);
  }
  Voltage = Voltage / 1000.0; // average value

  // ACS712 conversion (for 5A module sensitivity = 185mV/A)
  Current = (Voltage - 2.5) / 0.100;

  // Print results
  Serial.print("\nVoltage Sensed (V) = ");
  Serial.print(Voltage, 2); // 2 decimal places
  Serial.print("\t Current (A) = ");
  Serial.print(Current, 2); // 2 decimal places

  delay(1000);
}
