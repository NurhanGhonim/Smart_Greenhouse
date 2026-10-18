
#ifndef CONFIG_H
#define CONFIG_H

#define DHT_PIN 4
#define LDR_PIN 34
#define SERVO_PIN 13
#define RELAY_PIN 26

#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_ADDRESS 0x3C

#define TEMP_MIN 20.0f
#define TEMP_MAX 35.0f
#define DARK_THRESHOLD 1500

#define SENSOR_INTERVAL_MS 2000
#define MQTT_PUBLISH_INTERVAL_MS 10000

#define RELAY_ON_LEVEL LOW
#define RELAY_OFF_LEVEL HIGH

#endif
