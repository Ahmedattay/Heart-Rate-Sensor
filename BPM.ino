#include <Wire.h>
#include "MAX30105.h"
#include "heartRate.h"

MAX30105 particleSensor;

const byte MAX_READINGS = 20; // Number of consistent readings before stopping
byte bpmReadings[MAX_READINGS];
byte readingCount = 0;
long lastBeat = 0;

float beatsPerMinute = 0;
int averageBPM = 0;
bool done = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing...");

  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 was not found. Please check wiring/power.");
    while (1);
  }

  Serial.println("Place your finger on the sensor...");
  particleSensor.setup();
  particleSensor.setPulseAmplitudeRed(0x0A);
  particleSensor.setPulseAmplitudeGreen(0);
}

void loop() {
  if (done) return; // Stop once final result is printed

  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue)) {
    long delta = millis() - lastBeat;
    lastBeat = millis();

    beatsPerMinute = 60 / (delta / 1000.0);

    // Consider valid if BPM is in a realistic range
    if (beatsPerMinute > 40 && beatsPerMinute < 180) {
      bpmReadings[readingCount++] = (byte)beatsPerMinute;

      // Print BPM for Serial Plotter (one value per line = one graph)
      Serial.println(beatsPerMinute);
    }
  }

  // After collecting enough consistent readings
  if (readingCount >= MAX_READINGS) {
    int sum = 0;
    for (byte i = 0; i < MAX_READINGS; i++)
      sum += bpmReadings[i];

    averageBPM = sum / MAX_READINGS;

    Serial.println("-----------");
    Serial.print("Final Average BPM (from ");
    Serial.print(MAX_READINGS);
    Serial.println(" readings): ");
    Serial.println(averageBPM);
    Serial.println("-----------");

    done = true;
  }
}