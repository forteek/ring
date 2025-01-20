#include <Arduino.h>
#include "Encoder.h"

Encoder encoder(25, 26, 27);

void setup() {
    Serial.begin(115200);
}

void loop() {
    encoder.process();
    if (encoder.isChanged()) {
        Serial.println(encoder.getValue());
    }
    if (encoder.isButtonPressed()) {
        Serial.println("klik");
    }
}
