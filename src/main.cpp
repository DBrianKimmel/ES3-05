// Name:     ES3-05  main.cpp
// Updated:  2026-05-24

// Board: ESP32-S3-ETH

//==============
// Basic
#include <Arduino.h>

//==============
// Bluetooth and BLE

// #define HAS_BLUETOOTH true
// #define HAS_BLE true

//==============
// camera

// #define HAS_CAMERA true

//==============
// Ethernet

// #define HAS_ETHERNET false

//==============
// RGBLed

#define HAS_RGBLED() 1
#if HAS_RGBLED()
#include "RgbLed.hpp"
void rgbSetup();
void rgbLoop();
#endif

//==============
// OTA and/or OTW

// #define OTA 1
// #define OtaEthernet 1
// #define OtaThread

//==============
// SDCard

#define HAS_SDCARD false
#if HAS_SDCARD
#include <SD.h>
#endif

//==============
// Thread

#define HAS_THREAD false
#if HAS_THREAD
#include <Thread.h>
#endif

//==============
// WiFi
#define HAS_WIFI_STA() 1
#if HAS_WIFI_STA()
#include "WiFi-Sta.hpp"
#endif

//==============
// Zigbee

#define HAS_ZIGBEE false
#if HAS_ZIGBEE
#endif

// Other definitions can be added here, e.g. for sensors, displays, etc.

//============================================================================================//

void setup()
{
    Serial.begin(115200);
    Serial.println("Hello World - I am starting now.");

#if HAS_RGBLED()
    rgbSetup();
#endif
#if HAS_WIFI_STA()
    wifiStaSetup();
#endif

}

//============================================================================================//

void loop()
{

#if HAS_RGBLED()
    rgbLoop();
#endif

#if HAS_WIFI_STA()
    wifiStaLoop();

#endif
}

//============================================================================================//

// ### END DBK
