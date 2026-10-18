
#include <Arduino.h>
#include <DHT.h>

// Sensor pins
#define DHT_PIN 4
#define DHT_TYPE DHT11
#define LDR_PIN 34

// Data collection interval
const unsigned long SAMPLE_INTERVAL_MS = 2000;

DHT dht(DHT_PIN, DHT_TYPE);

unsigned long lastSampleTime = 0;

void setup() {
    Serial.begin(115200);
    delay(1500);

    dht.begin();

    analogReadResolution(12);
    pinMode(LDR_PIN, INPUT);

    // CSV header: print once after starting
    Serial.println("time_ms,temperature_c,humidity_pct,light_raw");
}

void loop() {
    unsigned long now = millis();

    if (now - lastSampleTime >= SAMPLE_INTERVAL_MS) {
        lastSampleTime = now;

        float temperature = dht.readTemperature();
        float humidity = dht.readHumidity();
        int light = analogRead(LDR_PIN);

        // Skip invalid DHT readings
        if (isnan(temperature) || isnan(humidity)) {
            Serial.println("ERROR,DHT_READ_FAILED");
            return;
        }

        // Send one CSV row to the computer
        Serial.print(now);
        Serial.print(",");
        Serial.print(temperature, 2);
        Serial.print(",");
        Serial.print(humidity, 2);
        Serial.print(",");
        Serial.println(light);
    }
}
