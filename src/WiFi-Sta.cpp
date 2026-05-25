// Name:     ES3-05  WiFi-Sta.cpp
// Updated:  2026-05-26

#include "WiFi-Sta.hpp"

void wifiStaSetup()
{
    // Implementation for WiFi STA setup
}

void wifiStaLoop()
{
    // Implementation for WiFi STA loop
    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Wi-Fi Setup done.");
}

void wifiStaSetup();
void wifiStaLoop();

// ### END DBK
