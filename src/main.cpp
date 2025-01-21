#include <Arduino.h>
#include <ESP32Encoder.h>
#include <OneButton.h>
#include <SPI.h>
#include <Wire.h>
#include <WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Menu.h"
#include "WifiScanMenu.h"


ESP32Encoder encoder;
OneButton button(27, true);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

WifiScanMenu wifiScanMenu;
Scene *currentScene = &wifiScanMenu;

void setup() {
	ESP32Encoder::useInternalWeakPullResistors = puType::up;
	encoder.attachHalfQuad(26, 25);
	encoder.clearCount();

	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
		Serial.println(F("SSD1306 allocation failed"));
		for(;;);
	}

	wifiScanMenu.init(&display, &encoder, &button);

    Serial.begin(115200);
}

void loop() {
	currentScene->loop();
	currentScene->draw();
}
