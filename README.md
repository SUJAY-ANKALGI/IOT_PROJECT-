# IOT_PROJECT- Current and Voltage Monitoring with Arduino (ACS712)  
This project measures real-time voltage and current from a DC load using an ACS712 Hall-effect current sensor and an analog voltage divider connected to an Arduino. The data is read by the Arduino’s ADC and displayed on the Serial Monitor.

✨ Features

📡 Simultaneous Voltage & Current Sensing
⚡ Real-Time Monitoring on Serial Monitor
📝 Calibrated Readings with offset removal
📊 Ready for Graph Plotting / Logging to PC

🛠️ Hardware Used

Arduino Uno / Nano (any compatible board)
ACS712 Current Sensor (5 A / 20 A / 30 A variant)
Voltage divider for DC voltage measurement
DC Load (motor, LED strip, etc.)
Jumper wires & breadboard

📄 How It Works
The ACS712 outputs a voltage proportional to the measured current.
A voltage divider scales the input voltage into Arduino’s 0–5 V ADC range.
The Arduino reads both analog signals, applies calibration, and prints the Voltage (V) and Current (A) to Serial Monitor.
