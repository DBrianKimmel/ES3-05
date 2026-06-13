// Name:     ES3-05  test_device_main.cpp
// Updated:  2026-06-13

// https://medium.com/engineering-iot/unit-testing-on-esp32-with-platformio-a-step-by-step-guide-d33f3241192b

#include <Arduino.h>
#include <unity.h>
#include "WiFiManager.h"

WiFiManager wifiManager;

// Mock Wi-Fi credentials
const char* TEST_SSID = "TestSSID";
const char* TEST_PASSWORD = "TestPassword";

// Test: Wi-Fi connection timeout
void test_wifi_connection_timeout() {
    wifiManager.begin(TEST_SSID, TEST_PASSWORD);
    TEST_ASSERT_FALSE(wifiManager.isConnected());
}

// Test: Get IP address when disconnected
void test_get_ip_address_disconnected() {
    String ip = wifiManager.getIPAddress();
    TEST_ASSERT_EQUAL_STRING("Not Connected", ip.c_str());
}

void setup() {
    UNITY_BEGIN();

    RUN_TEST(test_wifi_connection_timeout);
    RUN_TEST(test_get_ip_address_disconnected);

    UNITY_END();
}

void loop() {
    // Not used for unit testing
}

// ### END DBK
