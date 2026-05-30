// Name:     ES3-05  WiFi-Sta.cpp
// Updated:  2026-05-26

#include "WiFi-Sta.hpp"

#include <WiFi.h>

// ========== Pin Definitions ==========

char *wifiSsid = "PinkPoppyIoT";
char *wifiPassword = "Plumtree17";

void wifiStaSetup()
{
    // Implementation for WiFi STA setup
    Serial.println("Connecting to WiFi...");

    // Begin Wi-Fi connection
    WiFi.begin(wifiSsid, wifiPassword);

    // Wait until connected
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    // Connection successful
    Serial.println();
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP()); // Print assigned IP address
}

void wifiStaLoop()
{
    // Implementation for WiFi STA loop
    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    // WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Wi-Fi Setup done.");
}

void wifiStaSetup();
void wifiStaLoop();

// ### END DBK
