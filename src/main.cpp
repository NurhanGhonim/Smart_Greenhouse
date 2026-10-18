
#include <Arduino.h>

#include "config.h"
#include "dht_driver.h"
#include "ldr_driver.h"
#include "servo_driver.h"
#include "relay_driver.h"
#include "oled_driver.h"
#include "ml_driver.h"

void setup() {
    Serial.begin(115200);

    dhtDriverBegin();
    ldrDriverBegin();
    servoDriverBegin();
    relayDriverBegin();
    oledDriverBegin();

    bool modelReady = mlDriverBegin();

    Serial.println("Greenhouse drivers initialized");
    Serial.print("ML model ready: ");
    Serial.println(modelReady ? "YES" : "NO");
}

void loop() {
    DHTReading reading = dhtDriverRead();
    int light = ldrDriverRead();

    if (reading.valid) {
        Serial.printf(
            "Temperature: %.1f C, Humidity: %.1f %%\n",
            reading.temperature,
            reading.humidity
        );
    } else {
        Serial.println("Invalid DHT reading");
    }

    Serial.printf("Light ADC: %d\n", light);

    delay(SENSOR_INTERVAL_MS);
}
