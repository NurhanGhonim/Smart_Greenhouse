#include <Arduino.h>
#include "config.h"
#include "ldr_driver.h"

void ldrDriverBegin() {
    pinMode(LDR_PIN, INPUT);
    analogReadResolution(12);
}

int ldrDriverRead() {
    return analogRead(LDR_PIN);
}