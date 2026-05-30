// Name:     ES3-05  RgbLed.hpp
// Updated:  2026-05-29

#ifndef RGBLED_H
#define RGBLED_H

#include <Adafruit_NeoPixel.h>

// ========== Pin Definitions ==========
// The pin is not well documented so try 21, 22, or 23 if 21 doesn't work. The onboard RGB LED is connected to GPIO 21 on the ESP32-S3-ETH board.
#define RGB_LED_PIN 21              // GPIO pin connected to the onboard RGB LED

// ========== RGB LED Configuration ==========
#define RGB_LED_COUNT 1             // Number of RGB LEDs in the strip (1 for onboard RGB LED)
#define RGB_LED_LED1 -1             // Index of the first LED in the strip (0-based index, -1 if not used)
#define RGB_LED_BLINK_INTERVAL 1000 // interval at which to blink LED (milliseconds)
#define RGB_LED_MAX_STATES 3        // Number of states in the RGB LED cycle (Red, Green, Blue)

void rgbSetup();
void rgbLoop();

#endif // RGBLED_H

// ### END DBK
