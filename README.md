# Smart_Greenhouse
# 🌱 Smart Greenhouse Using ESP32

## 📌 Project Overview

The **Smart Greenhouse** is an embedded systems project based on the ESP32 microcontroller. It monitors environmental conditions using sensors and controls a servo motor according to the light intensity detected by an LDR sensor.

The system measures temperature, humidity, and light intensity. Sensor readings are displayed on an OLED screen and transmitted through Serial communication for monitoring and data collection.

## 🎯 Objectives

- Monitor temperature and humidity using a DHT11 sensor.
- Measure light intensity using an LDR analog sensor.
- Automatically control a servo motor based on a predefined light threshold.
- Display sensor readings and servo status on an OLED screen.
- Transmit sensor data to a computer for logging and analysis.

## 🧰 Hardware Components

| Component | Purpose |
|---|---|
| ESP32 DevKit / ESP32-WROOM-32 | Main microcontroller |
| DHT11 | Temperature and humidity measurement |
| LDR sensor module | Light intensity measurement |
| SG90 or compatible servo motor | Actuator control |
| SSD1306 OLED display | Displaying sensor readings |
| External regulated 5V supply | Servo power |
| Jumper wires and breadboard | Circuit connections |

## 🔌 Pin Connections

| Component | Pin | ESP32 Connection |
|---|---|---|
| DHT11 | DATA | GPIO 4 |
| LDR module | AO | GPIO 34 |
| OLED | SDA | GPIO 21 |
| OLED | SCL | GPIO 22 |
| Servo | Signal | GPIO 18 |

### Power Connections

- DHT11: connect VCC to 3.3V when supported and GND to ESP32 GND.
- LDR module: connect its supply according to the module specifications and GND to ESP32 GND.
- OLED: connect VCC to the voltage supported by your display module, GND to GND, SDA to GPIO 21, and SCL to GPIO 22.
- Servo: connect its signal wire to GPIO 18 and its power wire to a suitable regulated 5V supply. Connect the supply ground to ESP32 GND.

**Important:** Do not power the servo from the ESP32 3.3V pin. Use a suitable external supply and a common ground.

## ⚙️ System Operation

The system reads the LDR sensor every 2 seconds.

The current servo-control rule is:

| LDR Reading | System Interpretation | Servo Behavior |
|---|---|---|
| Below 2000 | Bright condition | Keep the current position |
| 2000 or above | Dark condition | Move to 90° |

The threshold is configurable in `config.h`:

```cpp
#define LDR_THRESHOLD 2000
#define SERVO_PIN 18
#define SERVO_OPEN_ANGLE 90
#define SERVO_CLOSED_ANGLE 0
```

**Note:** The brightness interpretation assumes that the LDR readings increase in darkness. Actual readings depend on the sensor module and its circuit. The current control logic holds the last servo position when the reading falls below the threshold.

## 🖥️ OLED Display

The SSD1306 OLED displays:

- Temperature in degrees Celsius
- Relative humidity percentage
- Raw LDR reading
- Light-condition status
- Current servo angle

## 📡 Serial Data Logging

The ESP32 sends comma-separated sensor readings at 115200 baud.

The output format is:

```text
time_ms,temperature_c,humidity_pct,light_raw,servo_angle,ldr_action
```

Example:

```text
2000,27.40,61.00,1850,0,BRIGHT_NO_CHANGE
4000,27.50,60.80,2500,90,DARK_SERVO_MOVE
```

The data can be collected using the Arduino Serial Monitor or a Python/Jupyter Notebook script.

## 🧑‍💻 Software and Libraries

- Arduino IDE
- ESP32 Arduino Core
- Adafruit DHT sensor library
- Adafruit Unified Sensor
- Adafruit SSD1306
- Adafruit GFX Library
- ESP32Servo

Install the required libraries through **Arduino IDE → Library Manager**.

## 📁 Project Structure

```text
Smart_Greenhouse/
├── Smart_Greenhouse.ino
├── config.h
├── dht_driver.h
├── dht_driver.cpp
├── ldr_driver.h
├── ldr_driver.cpp
├── oled_driver.h
├── oled_driver.cpp
├── servo_driver.h
└── servo_driver.cpp
```

The exact structure may vary depending on whether the project is built with Arduino IDE or PlatformIO.

## 🚀 Getting Started

1. Install Arduino IDE and the ESP32 board package.
2. Install the required libraries.
3. Connect the sensors, OLED display, and servo according to the pin table.
4. Open `Smart_Greenhouse.ino`.
5. Select the correct ESP32 board and COM port.
6. Upload the program.
7. Open Serial Monitor at **115200 baud**.
8. Observe the sensor readings and test the LDR threshold.

## 🔮 Future Improvements

- Add automatic ventilation using a fan.
- Add irrigation control based on soil moisture.
- Integrate Wi-Fi monitoring and MQTT communication.
- Build a web dashboard for real-time monitoring.
- Add historical data visualization and alerts.

## 👩‍🔬 Project Status

**Development in progress.**

This project is intended for educational purposes and demonstrates sensor integration, actuator control, embedded C++, and environmental monitoring using ESP32.
