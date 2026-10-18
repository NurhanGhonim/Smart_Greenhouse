#ifndef OLED_DRIVER_H
#define OLED_DRIVER_H

bool oledDriverBegin();

void oledDriverShow(
    float temperature,
    float humidity,
    int lightValue,
    bool dhtValid,
    int servoAngle
);

#endif