

#ifndef CONFIG_H
#define CONFIG_H

// DHT11 Sensor
#define DHT_PIN 4
#define DHT_TYPE 11

// LDR Analog Sensor
#define LDR_PIN 34
#define LDR_THRESHOLD 2000

// OLED SSD1306
#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_ADDRESS 0x3C

// Servo Motor
#define SERVO_PIN 18
#define SERVO_CLOSED_ANGLE 0
#define SERVO_OPEN_ANGLE 90

// Serial Communication
#define SERIAL_BAUD_RATE 115200

// Sensor Sampling Interval
#define SENSOR_INTERVAL_MS 2000

#endif
