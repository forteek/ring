//
// Created by Marcin Fortuniak on 20/01/2025.
//

#include "Menu.h"

void Menu::init(
    Adafruit_SSD1306* display,
    ESP32Encoder* encoder,
    OneButton* button,
    std::vector<MenuItem> items
) {
    this->items = items;
    Scene::init(display, encoder, button);

    display->clearDisplay();
    display->setTextSize(1);
    display->setTextColor(WHITE);

    const uint lines = items.size() < 8 ? items.size() : 8;
    for (int i = 0; i < lines; i++) {
        MenuItem item = items[i];

        display->drawBitmap(0, 8 * i, item.icon.begin(), 7, 7, WHITE);
        display->setCursor(8, 8 * i);
        display->println(item.name.c_str());
    }
    display->display();
}

void Menu::loop() {
    button->tick();
    int16_t encoderValue = encoder->getCount();
    if (encoderValue != 0) {
        Serial.println(encoderValue);
    }
}

void Menu::draw() {
    // display->clearDisplay();
    // display->setTextSize(1);
    // display->setTextColor(WHITE);
    // display->setCursor(0, 0);
    // display->println("Menu");
    // display->display();
}
