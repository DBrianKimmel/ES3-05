// Name:     ES3-05  RgbLed.h
// Updated:  2026-05-26

#ifndef RGBLED_H
#define RGBLED_H

#include <Adafruit_NeoPixel.h>

// The pin is not well documented so try 21, 22, or 23 if 21 doesn't work. The onboard RGB LED is connected to GPIO 21 on the ESP32-S3-ETH board.
#define RGB_LED_PIN 21
#define RGB_LED_COUNT 1
#define RGB_LED_LED1 -1
#define RGB_LED_BLINK_INTERVAL 1000 // interval at which to blink LED (milliseconds)
#define RGB_LED_MAX_STATES

int rgbLedState = 0;
int rgbLedRed = 0;
int rgbLedGreen = 0;
int rgbLedBlue = 0;
int rgbLedStep = 64;
unsigned long rgbPreviousMillis = 0;   // will store last time LED was updated

#endif // RGBLED_H

// ### END DBK
