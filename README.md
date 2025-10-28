# DHT11-Temperature-Humidity-Monitor-Arduino-

This project details an Arduino-based system designed to measure and display real-time temperature and humidity data using the DHT11 sensor. Data is shown on an LCD display and simultaneously sent over serial communication
Wiring Connections
DHT11 Sensor:
VCC to Arduino 5V
GND to Arduino GND
DATA to Arduino Digital Pin 2 (or any other digital pin you define)
16x2 LCD Display (Standard without I2C module):
VSS to Arduino GND
VDD to Arduino 5V
VO to the middle pin of a 10kΩ Potentiometer (other two pins to 5V and GND for contrast control)
RS to Arduino Digital Pin 12
RW to Arduino GND
EN to Arduino Digital Pin 11
D4 to Arduino Digital Pin 5
D5 to Arduino Digital Pin 4
D6 to Arduino Digital Pin 3
D7 to Arduino Digital Pin 2
A (LED+) to Arduino 5V (or through a 220Ω resistor for backlight control)
K (LED-) to Arduino GND
Note: If you are using an I2C LCD module, wiring is much simpler (SDA, SCL, VCC, GND). The provided code will need slight modifications to use the LiquidCrystal_I2C library instead of LiquidCrystal.
Software Requirements
Arduino IDE: To write, compile, and upload the code.
DHT sensor library by Adafruit: Install via Arduino IDE's Library Manager.
Sketch > Include Library > Manage Libraries...
Search for "DHT sensor library" by Adafruit and install.
Adafruit Unified Sensor library: A dependency for the DHT sensor library. Install this as well.
LiquidCrystal Library: This is usually pre-installed with the Arduino IDE.
Setup and Calibration
Assemble the Circuit: Follow the wiring diagram to connect your DHT11 sensor and LCD to the Arduino.
Install Libraries: Open the Arduino IDE, go to Sketch > Include Library > Manage Libraries..., and install "DHT sensor library by Adafruit" and "Adafruit Unified Sensor". Ensure the LiquidCrystal library is available.
Upload Code: Copy the provided Arduino code, paste it into the Arduino IDE, select your Arduino board (Tools > Board) and port (Tools > Port), then upload.
LCD Contrast: If your LCD is blank or unreadable, adjust the potentiometer connected to pin VO until the text is clear.
Verification: Open the Serial Monitor in the Arduino IDE (Tools > Serial Monitor) at 9600 baud. You should see temperature and humidity readings every 2 seconds. Simultaneously, the data will appear on your LCD.
Power Consumption Estimation
For this setup, power consumption is relatively low.
Arduino Uno: Around 40-50mA.
DHT11 Sensor: Typically 0.5-2.5mA when active, much less in sleep mode.
16x2 LCD (with backlight): Can range from 20mA (for basic operation) to 100-150mA with a bright backlight. (Using a current-limiting resistor for the backlight helps control this).
Total estimated consumption could be in the range of 70mA to 200mA, depending heavily on the LCD's backlight usage. For long-term battery-powered applications, consider using an I2C LCD (which can sometimes be more efficient, though not always significantly) or implementing sleep modes for the Arduino.
Lessons Learned
Sensor Interfacing: Gained hands-on experience connecting and reading data from a digital sensor (DHT11).
Serial Communication: Utilized the Arduino's serial port for debugging and data output to a computer.
LCD Display Control: Learned how to initialize and write data to a character LCD display.
Library Usage: Understood the importance and practical application of external libraries for complex components.
Basic Troubleshooting: Faced and resolved issues related to wiring, library installation, and data interpretation (e.g., isnan check for sensor errors).
Power Management (Conceptual): Understood the different current draws of components and the implications for power supply design.
Future Enhancements
Data Logging: Store data to an SD card module or send it to a cloud service (e.g., ThingSpeak) via a Wi-Fi module (ESP8266/ESP32).
Alerts: Add an LED or buzzer to trigger when temperature or humidity exceeds certain thresholds.
Calibration Routine: Implement a more sophisticated calibration method if higher accuracy is needed.
Graphical Display: Upgrade to an OLED or graphical LCD for more visually appealing data representation.
RTC Module: Integrate a Real-Time Clock (RTC) module to timestamp logged data accurately.
