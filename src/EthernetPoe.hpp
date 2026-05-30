// Name:     ES3-05  EthernetPoe.hpp
// Updated:  2026-05-27

// === Network port control pin description ===
// Network port interface	ESP32-S3-ETH GPIO
// MISO                 	GPIO12
// MOSI                 	GPIO11
// SCLK                 	GPIO13
// CS                   	GPIO14
// RST                  	GPIO9
// INT                  	GPIO10

#ifndef ETHERNET_H
#define ETHERNET_H

#include "EthernetPoe.hpp"
#include <SPI.h>
#include <Ethernet.h>

#define W5500_CS_PIN 14   // GPIO pin connected to Ethernet module Chip Select pin
#define W5500_RST_PIN 9   // GPIO pin connected to Ethernet module Reset pin
#define W5500_INT_PIN 10  // GPIO pin connected to Ethernet module Interrupt pin
#define W5500_MISO_PIN 12 // MISO pin
#define W5500_MOSI_PIN 11 // MOSI pin
#define W5500_SCK_PIN 13  // Clock pin

// #define W5500_HARD_RESET             // Uncomment if using the W5500_RST_PIN for hardware reset of the Ethernet module
#define ETHERNET_MAC_ADDRESS {0x02, 0x00, 0xBE, 0xEF, 0xFE, 0xED} // MAC address for Ethernet (must be unique on the network)
#define ETHERNET_DRIVER W5500                                     // Ethernet driver type  (W5500, W5100, W5100S, LAN8720, etc.)

void ethernetSetup();

void ethernetLoop();

#endif // ETHERNET_H

// ### END DBK
