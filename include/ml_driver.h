
#ifndef ML_DRIVER_H
#define ML_DRIVER_H

struct MLFeatures {
    float temperature;
    float humidity;
    float light;
};

struct MLPrediction {
    int classId;
    float confidence;
    bool valid;
};

bool mlDriverBegin();
MLPrediction mlDriverPredict(const MLFeatures &features);

#endif
