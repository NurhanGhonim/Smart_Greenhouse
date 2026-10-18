
#ifndef GREENHOUSE_STATE_H
#define GREENHOUSE_STATE_H

#include "ml_driver.h"

enum OperatingMode {
    MODE_AUTO,
    MODE_MANUAL
};

struct GreenhouseState {
    float temperature;
    float humidity;
    int lightRaw;

    int servoAngle;
    bool relayOn;

    bool sensorValid;
    bool wifiConnected;
    bool mqttConnected;

    OperatingMode mode;
    MLPrediction prediction;
};

#endif
