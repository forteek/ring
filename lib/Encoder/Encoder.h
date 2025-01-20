#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>
#include "Button.h"

class Encoder {
public:
    Encoder(uint8_t clkPin, uint8_t dtPin, uint8_t swPin);

    bool isChanged();
    int16_t getValue() const;
    bool isButtonPressed();
    void process();

private:
    uint8_t clkPin;
    uint8_t dtPin;

    int16_t value;
    bool changed;

    Button button;

    void processRotation();
};

#endif // ENCODER_H
