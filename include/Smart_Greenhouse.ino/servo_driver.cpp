#include <Arduino.h>
#include <ESP32Servo.h>

#include "config.h"
#include "servo_driver.h"

static Servo greenhouseServo;
static int currentAngle = SERVO_CLOSED_ANGLE;

void servoDriverBegin() {
    greenhouseServo.setPeriodHertz(50);

    greenhouseServo.attach(
        SERVO_PIN,
        500,
        2400
    );

    greenhouseServo.write(currentAngle);
}

void servoDriverSetAngle(int angle) {
    angle = constrain(angle, 0, 180);

    greenhouseServo.write(angle);
    currentAngle = angle;
}

int servoDriverGetAngle() {
    return currentAngle;
}