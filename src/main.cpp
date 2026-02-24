#include <Arduino.h>
#include <PZEM004Tv30.h>

// PZEM-004T communicates via Serial2 on ESP32
// Default pins: RX=GPIO16, TX=GPIO17
// You can change these pins if needed
#define PZEM_RX_PIN 16
#define PZEM_TX_PIN 17

// Create PZEM object with custom RX/TX pins
PZEM004Tv30 pzem(Serial2, PZEM_RX_PIN, PZEM_TX_PIN);

void setup() {
  // Initialize serial for debugging
  Serial.begin(115200);
  Serial.println("PZEM-004T Power Monitor");
  Serial.println("========================");
  
  // Wait a moment for sensor to initialize
  delay(1000);
}

void loop() {
  // Read voltage (V)
  float voltage = pzem.voltage();
  
  // Read current (A)
  float current = pzem.current();
  
  // Read power (W)
  float power = pzem.power();
  
  // Read energy (kWh)
  float energy = pzem.energy();
  
  // Read frequency (Hz)
  float frequency = pzem.frequency();
  
  // Read power factor
  float pf = pzem.pf();
  
  // Check if reading was successful
  if (isnan(voltage)) {
    Serial.println("Error reading from PZEM-004T sensor!");
    Serial.println("Check wiring and connections.");
  } else {
    // Display all readings
    Serial.println("\n--- Power Readings ---");
    Serial.print("Voltage:      "); Serial.print(voltage, 1); Serial.println(" V");
    Serial.print("Current:      "); Serial.print(current, 3); Serial.println(" A");
    Serial.print("Power:        "); Serial.print(power, 1); Serial.println(" W");
    Serial.print("Energy:       "); Serial.print(energy, 3); Serial.println(" kWh");
    Serial.print("Frequency:    "); Serial.print(frequency, 1); Serial.println(" Hz");
    Serial.print("Power Factor: "); Serial.println(pf, 2);
    Serial.println("---------------------");
  }
  
  // Wait 2 seconds before next reading
  delay(2000);
}