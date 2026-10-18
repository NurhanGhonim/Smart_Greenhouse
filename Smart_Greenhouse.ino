
#include <Arduino.h>
#include "config.h"
#include "dht_driver.h"
#include "ldr_driver.h"

// Time of the last sensor reading
unsigned long lastSampleTime = 0;

void setup() {
    // Start serial communication with the computer
    Serial.begin(SERIAL_BAUD_RATE);
    delay(1000);

    // Initialize sensors
    dhtDriverBegin();
    ldrDriverBegin();

    // CSV header for the Jupyter Notebook
    Serial.println(
        "time_ms,temperature_c,humidity_pct,light_raw"
    );
}

void loop() {
    unsigned long currentTime = millis();

    // Collect data every SENSOR_INTERVAL_MS
    if (currentTime - lastSampleTime >= SENSOR_INTERVAL_MS) {
        lastSampleTime = currentTime;

        // Read temperature and humidity
        DHTReading reading = dhtDriverRead();

        // Read light intensity
        int lightValue = ldrDriverRead();

        // Skip the row if DHT11 reading failed
        if (!reading.valid) {
            Serial.println("ERROR,DHT_READ_FAILED");
            return;
        }

        // Send the data as a CSV row
        Serial.print(currentTime);
        Serial.print(",");

        Serial.print(reading.temperature, 2);
        Serial.print(",");

        Serial.print(reading.humidity, 2);
        Serial.print(",");

        Serial.println(lightValue);
    }
}
