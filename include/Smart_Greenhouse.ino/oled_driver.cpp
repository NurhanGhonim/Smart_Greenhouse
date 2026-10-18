
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"
#include "oled_driver.h"

static Adafruit_SSD1306 display(
    OLED_WIDTH,
    OLED_HEIGHT,
    &Wire,
    -1
);

bool oledDriverBegin() {
    Wire.begin(OLED_SDA, OLED_SCL);

    if (!display.begin(
            SSD1306_SWITCHCAPVCC,
            OLED_ADDRESS
        )) {
        return false;
    }

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);

    display.println("Smart Greenhouse");
    display.println("Initializing...");
    display.display();

    return true;
}

void oledDriverShow(
    float temperature,
    float humidity,
    int lightValue,
    bool dhtValid,
    int servoAngle
) {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);

    display.println("SMART GREENHOUSE");
    display.println("----------------");

    if (dhtValid) {
        display.print("Temp: ");
        display.print(temperature, 1);
        display.println(" C");

        display.print("Humidity: ");
        display.print(humidity, 1);
        display.println(" %");
    } else {
        display.println("DHT11 read failed");
    }

    display.print("Light: ");
    display.println(lightValue);

    if (lightValue >= LDR_THRESHOLD) {
        display.println("DARK - SERVO MOVE");
    } else {
        display.println("BRIGHT - NO CHANGE");
    }

    display.print("Servo: ");
    display.print(servoAngle);
    display.println(" deg");

    display.display();
}
