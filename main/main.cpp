// Name:     ES3-05  main.cpp
// Updated:  2026-05-17

// Board: ESP32-S3-ETH

//============================================================================================//

//==============
// Basic
#include <Arduino.h>

//==============
// Bluetooth and BLE
#define HAS_BLUETOOTH false
#define HAS_BLE false

//==============
// camera
#define HAS_CAMERA false

//==============
// Ethernet
// Initialize W5500 Ethernet module using DHCP and print the IP address.

#define HAS_ETHERNET true
#ifdef HAS_ETHERNET
#include <SPI.h>
#include <Ethernet.h>

// Define W5500 pin assignments
#define W5500_CS 14   // Chip Select pin
#define W5500_RST 9   // Reset pin
#define W5500_INT 10  // Interrupt pin
#define W5500_MISO 12 // MISO pin
#define W5500_MOSI 11 // MOSI pin
#define W5500_SCK 13  // Clock pin

// MAC address (can be arbitrary or set according to network requirements)
byte mac[] = {0x02, 0x00, 0x00, 0x12, 0x34, 0x56};

EthernetClient client;
#endif

//==============
// RGBLed
#define HAS_RGBLED true
#include "Adafruit_NeoPixel.h"
#define RGB_LED_PIN 4
// #define RGB_LED_PIN 21
#define RGB_LED_COUNT 1
#define LED1 -1
Adafruit_NeoPixel rgbLedOnboard = Adafruit_NeoPixel(RGB_LED_COUNT, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);

//==============
// OTA and/or OTW
// #define OTA
// #define OtaEthernet
// #define OtaThread

//==============
// SDCard

//==============
// Thread

//==============
// WiFi
#define HAS_WIFI false
#ifdef HAS_WIFI
#endif

//==============
// Zigbee

// Other definitions can be added here, e.g. for sensors, displays, etc.

//============================================================================================//
//============================================================================================//


//============================================================================================//

void setup()
{
    Serial.begin(115200);

    //==============
    // Initialize the RGB LED
    pinMode(LED1, OUTPUT);
    digitalWrite(LED1, HIGH); // Turn on the additional LED
    delay(100);               // Short delay to ensure the LED state is set before initializing the NeoPixel
    digitalWrite(LED1, LOW);  // Turn on the additional LED
    delay(100);               // Short delay to ensure the LED state is set before initializing the NeoPixel

    #ifdef HAS_ETHERNET
    Serial.println("Initializing Ethernet...");
    #endif
}

//============================================================================================//

void loop()
{
    Serial.println("Hello World");
    delay(2000);

//==============
#ifdef HAS_ETHERNET
    Serial.println("EthernetLoop: Attempting to initialize Ethernet...");
    // Initialize SPI with specified pin configuration
    SPI.begin(W5500_SCK, W5500_MISO, W5500_MOSI, W5500_CS);

    // Initialize Ethernet using DHCP to obtain an IP address
    Ethernet.init(W5500_CS);
    if (Ethernet.begin(mac) == 0)
    {
        Serial.println("Failed to configure Ethernet using DHCP");
        while (true)
            ; // Halt if DHCP configuration fails
    };

    // Print the assigned IP address
    Serial.print("IP Address: ");
    Serial.println(Ethernet.localIP());
#endif
}

//============================================================================================//

// ### END DBK
