// Name:     ES3-05  SdCard.cpp
// Updated:  2026-05-26

#include "SdCard.hpp"

// ========== Pin Definitions ==========
// The SD card is typically connected to the SPI pins. The default SPI pins for ESP32 are:
// SCK: GPIO 18
// MISO: GPIO 19
// MOSI: GPIO 23
// CS: GPIO 5 (you can change this to another GPIO if needed)
#define SD_CS_PIN 5 // GPIO pin used for SD card chip select

// ### END DBK
