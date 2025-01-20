#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Encoder.h"
#include <sstream>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Encoder encoder(25, 26, 27);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(115200);

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
}

void loop() {
    encoder.process();
    if (encoder.isChanged()) {
        Serial.println(encoder.getValue());
    }
    if (encoder.isButtonPressed()) {
        Serial.println("klik");
    }


    display.clearDisplay();

    // Display Text
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,28);

    std::ostringstream oss;
    oss << "JP " << encoder.getValue() << "%";

    display.println(oss.str().c_str());
    display.display();
}
