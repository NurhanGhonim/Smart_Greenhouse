#include <Arduino.h>
#include <DHT.h>

#include "config.h"
#include "dht_driver.h"

static DHT dht(DHT_PIN, DHT_TYPE);

void dhtDriverBegin() {
    dht.begin();
}

DHTReading dhtDriverRead() {
    DHTReading reading;

    reading.temperature = dht.readTemperature();
    reading.humidity = dht.readHumidity();

    reading.valid =
        !isnan(reading.temperature) &&
        !isnan(reading.humidity);

    return reading;
}