#include <Arduino.h>
#include <ESP32Encoder.h>
#include <OneButton.h>
#include <SPI.h>
#include <Wire.h>
#include <WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Menu.h"


ESP32Encoder encoder;
OneButton button(27, true);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

const std::array<uint8_t, 7> signal_max[] = {
	0b01111100, 0b10000010, 0b00111000, 0b01000100,
	0b00010000, 0b00000000, 0b00010000
};
const std::array<uint8_t, 7> signal_mid[] = {
	0b00000000, 0b00000000, 0b00111000, 0b01000100,
	0b00010000, 0b00000000, 0b00010000
};
const std::array<uint8_t, 7> signal_low[] = {
	0b00000000, 0b00000000, 0b00000000, 0b00000000,
	0b00010000, 0b00000000, 0b00010000
};

Menu mainMenu;
Scene *currentScene = &mainMenu;

void setup() {
	ESP32Encoder::useInternalWeakPullResistors = puType::up;
	encoder.attachHalfQuad(26, 25);
	encoder.clearCount();

	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) {
		Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}
	display.clearDisplay();

	WiFi.mode(WIFI_STA);
	int n = WiFi.scanNetworks();

	std::vector<MenuItem> items;
	for (int i = 0; i < n; i++) {
		const std::array<uint8_t, 7> *signal = WiFi.RSSI(i) > -70 ? signal_max : WiFi.RSSI(i) > -85 ? signal_mid : signal_low;

		items.push_back(MenuItem {
			WiFi.SSID(i).c_str(),
			[]() -> void { Serial.println("Item 1"); },
			nullptr,
			*signal
		});
	}

	mainMenu.init(&display, &encoder, &button, items);

    Serial.begin(115200);
}

void loop() {
	currentScene->loop();
	currentScene->draw();
}
