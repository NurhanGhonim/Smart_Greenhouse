#ifndef DHT_DRIVER_H
#define DHT_DRIVER_H

struct DHTReading {
    float temperature;
    float humidity;
    bool valid;
};

void dhtDriverBegin();
DHTReading dhtDriverRead();

#endif