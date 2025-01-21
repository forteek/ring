#include "WifiScanMenu.h"
#include <WiFi.h>

void WifiScanMenu::init(
    Adafruit_SSD1306* display,
    ESP32Encoder* encoder,
    OneButton* button
) {
    Scene::init(display, encoder, button);

    display->clearDisplay();
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(0, 28);
    display->println("Scanning networks...");
    display->display();

    WiFi.mode(WIFI_STA);
    int n = WiFi.scanNetworks();

    for (int i = 0; i < n; i++) {
        const std::array<uint8_t, 7> *signal = WiFi.RSSI(i) > -70 ? icon_signal_max : WiFi.RSSI(i) > -85 ? icon_signal_mid : icon_signal_low;

        this->items.push_back(MenuItem {
            WiFi.SSID(i).c_str(),
            []() -> void {},
            nullptr,
            *signal
        });
    }

    display->clearDisplay();
    const uint lines = n < 8 ? n : 8;
    for (int i = 0; i < lines; i++) {
        MenuItem item = items[i];

        display->drawBitmap(0, 8 * i, item.icon.begin(), 7, 7, WHITE);
        display->setCursor(8, 8 * i);
        display->println(item.name.c_str());
    }
    display->display();
    this->isInitialized = true;
}

void WifiScanMenu::loop() {
    if (!isInitialized) {
        return;
    }

    button->tick();
    int16_t encoderValue = encoder->getCount();
    if (encoderValue != 0) {
        Serial.println(encoderValue);
    }
}

void WifiScanMenu::draw() {
}
