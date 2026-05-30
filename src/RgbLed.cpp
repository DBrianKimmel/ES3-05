// Name:     ES3-05  RgbLed.cpp
// Updated:  2026-05-26

#include "RgbLed.hpp"
#include <Adafruit_NeoPixel.h>

// Define the NeoPixel object for the onboard RGB LED strip
// Assumes RGB_LED_COUNT and RGB_LED_PIN are defined in RgbLed.hpp
Adafruit_NeoPixel rgbLedOnboard(RGB_LED_COUNT, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);

int rgbLedRed = 0;
int rgbLedGreen = 0;
int rgbLedBlue = 0;
int rgbLedStep = 64;
int rgbLedState = 0;
unsigned long rgbLedCurrentMillis = 0;  // will store current time
unsigned long rgbLedPreviousMillis = 0; // will store last time LED was updated

// This function will be called to update the RGB LED display based on the current color values.
void rgbDisplay(int ix)
{
    // Update the color of the onboard RGB LED
    for (int i = 0; i < RGB_LED_COUNT; i++)
    {
        rgbLedOnboard.setPixelColor(i, rgbLedOnboard.Color(rgbLedRed, rgbLedGreen, rgbLedBlue));
    }
    rgbLedOnboard.show();
    Serial.println("Display new RGB LED color: R=" + String(rgbLedRed) + " G=" + String(rgbLedGreen) +
                   " B=" + String(rgbLedBlue) + "  Index=" + String(ix));
}

// This function will be called to update the RGB LED color values.
void rgbUpdateColor()
{
    rgbLedRed += rgbLedStep;
    if (rgbLedRed >= 255)
    {
        rgbLedRed = 0;
        rgbLedGreen += rgbLedStep;
        if (rgbLedGreen >= 255)
        {
            rgbLedGreen = 0;
            rgbLedBlue += rgbLedStep;
            if (rgbLedBlue >= 255)
            {
                rgbLedBlue = 0;
            }
        }
    }
}

// Get current time - if enough time has passed, update the RGB LED state and color values
void rgbDelay(int ix)
{
    if (rgbLedCurrentMillis - rgbLedPreviousMillis >= RGB_LED_BLINK_INTERVAL)
    {
        Serial.println("Updating RGB LED color for index " + String(ix));
        rgbLedPreviousMillis = rgbLedCurrentMillis;
        rgbUpdateColor();
        rgbDisplay(ix);
    }
}

// ========================================

// This function will be called to set up the RGB LED.
void rgbSetup()
{
    Serial.println("Setting up RGB LED...");
    // Initialize NeoPixel library
    rgbLedOnboard.begin();
    rgbLedOnboard.show(); // Ensure all pixels are off
    rgbLedState = 0;
    Serial.println("RGB LED setup complete.");
}

// This function will be called in the main loop to update the RGB LED state
void rgbLoop()
{
    rgbLedCurrentMillis = millis();

    // for each Rgb Led in a strip
    for (int ix = 0; ix < RGB_LED_COUNT; ix++)
    {
        rgbDelay(ix);
    }
}

// ### END DBK
