#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(uint8_t pin, bool triggerState);

    bool isPressed();
    void process();

private:
    uint8_t pin;

    bool buttonPressed;
    bool buttonReleased;
    bool triggerState;
};

#endif //BUTTON_H
