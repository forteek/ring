#include "Button.h"

Button::Button(uint8_t pin, bool triggerState) : pin(pin), triggerState(triggerState) {
    pinMode(pin, INPUT_PULLUP);

    this->buttonPressed = false;
    this->buttonReleased = true;
}

bool Button::isPressed() {
    if (this->buttonPressed) {
        this->buttonPressed = false;
        return true;
    }
    return false;
}

// todo could use some debounce - releasing after a long press tends to trigger another press
void Button::process() {
    const bool swState = digitalRead(this->pin);

    if (swState == this->triggerState && this->buttonReleased) {
        this->buttonPressed = true;
        this->buttonReleased = false;
    }

    if (swState != this->triggerState) {
        this->buttonPressed = false;
        this->buttonReleased = true;
    }
}
