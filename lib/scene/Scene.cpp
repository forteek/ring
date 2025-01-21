//
// Created by Marcin Fortuniak on 20/01/2025.
//

#include "Scene.h"

void Scene::init(Adafruit_SSD1306* display, ESP32Encoder* encoder, OneButton* button) {
    this->display = display;
    this->encoder = encoder;
    this->button = button;
}

void Scene::loop() {
}

void Scene::draw() {
    display->clearDisplay();
    display->setTextSize(1);
    display->setTextColor(WHITE);
    display->setCursor(0, 0);
    display->println("Scene");
    display->display();
}