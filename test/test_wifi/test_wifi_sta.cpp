// Name:     test_wifi_sta.cpp
// Updated:  2024-06-13
// https://github.com/jesdev-io/pioUnitTestingGuide
void setup () {
    delay(2000); // Wait for 2 seconds before starting the tests
}

void loop () {
    // Run the unit tests
    UNITY_BEGIN();
    // Add test cases here, e.g.:
    // RUN_TEST(test_wifi_connection_timeout);
    // RUN_TEST(test_get_ip_address_disconnected);
    UNITY_END();

    // Stop the loop after running tests
    while (true) {
        delay(1000);
    }
}

// ### END DBK
