#ifndef SCENE_H
#define SCENE_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Encoder.h>
#include <OneButton.h>

class Scene {
public:
    virtual void init(Adafruit_SSD1306* display, ESP32Encoder* encoder, OneButton* button);
    virtual void loop();
    virtual void draw();
protected:
    Adafruit_SSD1306 *display;
    ESP32Encoder *encoder;
    OneButton *button;
};

#endif //SCENE_H
