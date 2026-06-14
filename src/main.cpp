// Name:     ES3-05  main.cpp
// Updated:  2026-05-29

// Board: ESP32-S3-ETH

//==============
// Basic
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

//==============
// Bluetooth and BLE
#define HAS_BLUETOOTH() 0
#define HAS_BLE() 0
#if HAS_BLUETOOTH() || HAS_BLE()
#endif

//==============
// camera
#define HAS_CAMERA() 0
#if HAS_CAMERA()
#endif

//==============
// display
#define HAS_DISPLAY()
#if HAS_DISPLAY()
#include "Display.hpp"
#endif

//==============
// Ethernet
#define HAS_ETHERNET() 1
#if HAS_ETHERNET()
#include <EthernetPoe.hpp>
#endif

//==============
// MQTT
#define HAS_MQTT() 0
#if HAS_MQTT()
#endif

//==============
// RGBLed
#define HAS_RGBLED() 1
#if HAS_RGBLED()
#include "RgbLed.hpp"
#endif

//==============
// OTA and/or OTW
#define HAS_OTA() 0
// #define OtaEthernet 1
// #define OtaWiFi 1
// #define OtaThread
#if HAS_OTA()
#endif

//==============
// SDCard
#define HAS_SDCARD() 1
#if HAS_SDCARD()
#include <SdCard.hpp>
#endif

//==============
// Thread
#define HAS_THREAD() 0
#if HAS_THREAD()
#endif

//==============
// WiFi
#define HAS_WIFI_STA() 1
#if HAS_WIFI_STA()
#include "WiFi-Sta.hpp"
#endif

//==============
// Zigbee
#define HAS_ZIGBEE() 0
#if HAS_ZIGBEE()
#endif

// Other definitions can be added here, e.g. for sensors, displays, etc.

//============================================================================================//

void setup()
{
    // Start serial communication for debugging
    Serial.begin(115200);
    // while (!Serial)
    // {
    //     ; // Wait for the serial port to be ready
    // }
    delay(1000); // Give some time for the serial monitor to initialize
    Serial.println("Hello World - I am starting now.");

#if HAS_RGBLED()
    rgbSetup();
#endif
#if HAS_WIFI_STA()
    wifiStaSetup();
#endif
#if (HAS_ETHERNET())
    ethernetSetup();
#endif

    delay(1000); // Allow some time for setup routines to complete
    Serial.println("Hello World - I have completed the startup routines.");
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

#if (HAS_ETHERNET())
    ethernetLoop();
#endif

    // Add a small delay to avoid overwhelming the loop
    delay(100);
}

//============================================================================================//

// ### END DBK
