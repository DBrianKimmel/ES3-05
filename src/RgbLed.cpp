// Name : RgbLed.cpp
// Updated:  2026-05-26

#include "RgbLed.hpp"
#include <Adafruit_NeoPixel.h>

// Define the NeoPixel object for the onboard RGB LED strip
// Assumes RGB_LED_COUNT and RGB_LED_PIN are defined in RgbLed.hpp
Adafruit_NeoPixel rgbLedOnboard(RGB_LED_COUNT, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);

void rgbSetup()
{
    // Initialize NeoPixel library
    rgbLedOnboard.begin();
    rgbLedOnboard.show(); // Ensure all pixels are off
    rgbLedState = 0;
}

void rgbLoop()
{
    unsigned long rgbCurrentMillis = millis();

    for (int i = 0; i < RGB_LED_COUNT; i++)
    {
        rgbLedOnboard.setPixelColor(i, rgbLedOnboard.Color(255, 0, 0)); // Red
        rgbLedOnboard.show();
        delay(500);
        rgbLedOnboard.setPixelColor(i, rgbLedOnboard.Color(0, 255, 0)); // Green
        rgbLedOnboard.show();
        delay(500);
        rgbLedOnboard.setPixelColor(i, rgbLedOnboard.Color(0, 0, 255)); // Blue
        rgbLedOnboard.show();
        delay(500);
    }
}

// ### END DBK
