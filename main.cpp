#include <DHT.h>
#include <LiquidCrystal.h>

// Define DHT sensor type and pin
#define DHTPIN 2      // Digital pin connected to DHT sensor
#define DHTTYPE DHT11 // DHT 11

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize the LCD with the numbers of the interface pins
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println(F("DHT11 Temperature & Humidity Sensor Test!"));

  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD:
  lcd.print("Initializing...");

  dht.begin();
  delay(2000); // Give the sensor time to warm up
  lcd.clear();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Read humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    lcd.setCursor(0, 1);
    lcd.print("Check Wiring.");
    return;
  }

  // Display on Serial Monitor
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));

  // Display on LCD
  lcd.setCursor(0, 0); // Column 0, Row 0
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print((char)223); // Degree symbol
  lcd.print("C   ");

  lcd.setCursor(0, 1); // Column 0, Row 1
  lcd.print("Hum:  ");
  lcd.print(h);
  lcd.print("%   ");
}