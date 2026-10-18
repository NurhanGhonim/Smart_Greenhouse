
#include <Arduino.h>

#include "config.h"
#include "dht_driver.h"
#include "ldr_driver.h"
#include "oled_driver.h"
#include "servo_driver.h"

unsigned long lastSampleTime = 0;
bool oledReady = false;

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);
    delay(1000);

    dhtDriverBegin();
    ldrDriverBegin();

    oledReady = oledDriverBegin();

    servoDriverBegin();

    Serial.println(
        "time_ms,temperature_c,humidity_pct,"
        "light_raw,servo_angle,ldr_action"
    );

    if (!oledReady) {
        Serial.println("ERROR,OLED_INIT_FAILED");
    }
}

void loop() {
    unsigned long currentTime = millis();

    if (currentTime - lastSampleTime < SENSOR_INTERVAL_MS) {
        return;
    }

    lastSampleTime = currentTime;

    // Read LDR sensor
    int lightValue = ldrDriverRead();

    // If dark (LDR >= 2000), move servo to 90 degrees.
    // Otherwise, keep the previous servo position.
    if (lightValue >= LDR_THRESHOLD) {
        servoDriverSetAngle(SERVO_OPEN_ANGLE);
    }

    // Read DHT11 sensor
    DHTReading reading = dhtDriverRead();

    // Get the current servo angle
    int servoAngle = servoDriverGetAngle();

    // Update OLED display
    if (oledReady) {
        oledDriverShow(
            reading.temperature,
            reading.humidity,
            lightValue,
            reading.valid,
            servoAngle
        );
    }

    // Send data to Serial Monitor / Jupyter
    Serial.print(currentTime);
    Serial.print(",");

    if (reading.valid) {
        Serial.print(reading.temperature, 2);
        Serial.print(",");
        Serial.print(reading.humidity, 2);
    } else {
        Serial.print("NaN,NaN");
    }

    Serial.print(",");
    Serial.print(lightValue);
    Serial.print(",");
    Serial.print(servoAngle);
    Serial.print(",");

    if (lightValue >= LDR_THRESHOLD) {
        Serial.println("DARK_SERVO_MOVE");
    } else {
        Serial.println("BRIGHT_NO_CHANGE");
    }
}
