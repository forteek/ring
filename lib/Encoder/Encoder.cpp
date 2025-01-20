#include "Encoder.h"

Encoder::Encoder(uint8_t clkPin, uint8_t dtPin, uint8_t swPin) : clkPin(clkPin), dtPin(dtPin), button(swPin, LOW) {
    pinMode(clkPin, INPUT);
    pinMode(dtPin, INPUT);

    this->value = 0;
    this->changed = false;
}

bool Encoder::isChanged() {
    if (this->changed) {
        this->changed = false;
        return true;
    }
    return false;
}

bool Encoder::isButtonPressed() {
    return this->button.isPressed();
}

int16_t Encoder::getValue() const {
    return this->value;
}

void Encoder::process() {
    this->processRotation();
    this->button.process();
}

void Encoder::processRotation() {
    static uint8_t state = 0;
    const bool clkState = digitalRead(this->clkPin);
    const bool dtState = digitalRead(this->dtPin);

    switch (state) {
        default:
        case 0:
            if (!clkState) state = 1;
            else if (!dtState) state = 4;
        break;
        case 1:
            if (!dtState) state = 2;
        break;
        case 2:
            if (clkState) state = 3;
        break;
        case 3:
            if (clkState && dtState) {
                state = 0;
                ++this->value;
                this->changed = true;
            }
        break;
        case 4:
            if (!clkState) state = 5;
        break;
        case 5:
            if (dtState) state = 6;
        break;
        case 6:
            if (clkState && dtState) {
                state = 0;
                --this->value;
                this->changed = true;
            }
        break;
    }
}
