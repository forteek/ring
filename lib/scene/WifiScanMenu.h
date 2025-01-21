#ifndef WIFI_SCAN_MENU_H
#define WIFI_SCAN_MENU_H

#include <Arduino.h>
#include <vector>
#include "Menu.h"

const std::array<uint8_t, 7> icon_signal_max[] = {
    0b01111100, 0b10000010, 0b00111000, 0b01000100,
    0b00010000, 0b00000000, 0b00010000
};
const std::array<uint8_t, 7> icon_signal_mid[] = {
    0b00000000, 0b00000000, 0b00111000, 0b01000100,
    0b00010000, 0b00000000, 0b00010000
};
const std::array<uint8_t, 7> icon_signal_low[] = {
    0b00000000, 0b00000000, 0b00000000, 0b00000000,
    0b00010000, 0b00000000, 0b00010000
};

class WifiScanMenu: public Menu {
public:
    void init(
      Adafruit_SSD1306* display,
      ESP32Encoder* encoder,
      OneButton* button
    );
    void loop();
    void draw();
private:
    std::vector<MenuItem> items;
    bool isInitialized = false;
};

#endif //WIFI_SCAN_MENU_H
