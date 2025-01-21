//
// Created by Marcin Fortuniak on 20/01/2025.
//

#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include <vector>
#include "Scene.h"

struct MenuItem {
    std::string name;
    void (*action)();
    Scene* targetScene;
    std::array<uint8_t, 7> icon;
};

class Menu: public Scene {
public:
    void init(
      Adafruit_SSD1306* display,
      ESP32Encoder* encoder,
      OneButton* button,
      std::vector<MenuItem> items
    );
    void loop();
    void draw();
private:
    std::vector<MenuItem> items;
};

#endif //MENU_H
