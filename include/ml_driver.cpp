
#include <Arduino.h>
#include "ml_driver.h"

bool mlDriverBegin() {
    // TODO: Initialize the selected ML runtime and model.
    return false;
}

MLPrediction mlDriverPredict(const MLFeatures &features) {
    (void)features;

    MLPrediction result;
    result.classId = -1;
    result.confidence = 0.0f;
    result.valid = false;

    // TODO: Run the exported model here.
    return result;
}
