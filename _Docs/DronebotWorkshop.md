# DronebotWorkshop Article

```cpp
/*
  W5500 Ethernet DHCP Demo
  w5500_dhcp_demo.ino
  Shows basic operation of W5500 Ethernet module
  Uses W5500 Lite Ethernet module
  Uses Seeeduino XIAO ESP32-S3
  Uses Eth and WiFi Libraries
  DroneBot Workshop 2026
  https://dronebotworkshop.com
*/

#include <SPI.h>
#include <WiFi.h>  // ← required for WiFiEvent_t and WiFi.onEvent()
#include <ETH.h>

// ── Pin definitions ──────────────────────────────────────────────
#define W5500_CS_PIN 4    // D3  = GPIO4
#define W5500_RST_PIN 3   // D2  = GPIO3
#define W5500_INT_PIN -1  // Not wired
#define W5500_SCK_PIN 7   // D8  = GPIO7
#define W5500_MISO_PIN 8  // D9  = GPIO8
#define W5500_MOSI_PIN 9  // D10 = GPIO9

static bool ethConnected = false;

// ── Ethernet event handler ───────────────────────────────────────
void onEthEvent(WiFiEvent_t event) {
  switch (event) {

    case ARDUINO_EVENT_ETH_START:
      Serial.println("ETH: hardware started");
      ETH.setHostname("xiao-w5500");
      break;

    case ARDUINO_EVENT_ETH_CONNECTED:
      Serial.println("ETH: cable connected ✓");
      break;

    case ARDUINO_EVENT_ETH_GOT_IP:
      Serial.println("\n─── Network Configuration ───────────────────");
      Serial.print("  IP Address  : ");
      Serial.println(ETH.localIP());
      Serial.print("  Subnet Mask : ");
      Serial.println(ETH.subnetMask());
      Serial.print("  Gateway     : ");
      Serial.println(ETH.gatewayIP());
      Serial.print("  MAC Address : ");
      Serial.println(ETH.macAddress());
      Serial.print("  Link Speed  : ");
      Serial.print(ETH.linkSpeed());
      Serial.println(" Mbps");
      Serial.print("  Full Duplex : ");
      Serial.println(ETH.fullDuplex() ? "yes" : "no");
      Serial.println("─────────────────────────────────────────────");
      ethConnected = true;
      break;

    case ARDUINO_EVENT_ETH_DISCONNECTED:
      Serial.println("ETH: disconnected");
      ethConnected = false;
      break;

    case ARDUINO_EVENT_ETH_STOP:
      Serial.println("ETH: stopped");
      ethConnected = false;
      break;

    default:
      break;
  }
}

// ─────────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(115200);
  delay(1500);
  Serial.println("\n=== W5500 Lite — ETH.h Test ===\n");

  // Register event handler BEFORE calling ETH.begin()
  WiFi.onEvent(onEthEvent);

  Serial.println("Starting W5500 via ETH.begin()...");
  bool ok = ETH.begin(ETH_PHY_W5500,
                      1,
                      W5500_CS_PIN,
                      W5500_INT_PIN,
                      W5500_RST_PIN,
                      SPI2_HOST,
                      W5500_SCK_PIN,
                      W5500_MISO_PIN,
                      W5500_MOSI_PIN);

  if (!ok) {
    Serial.println("ETH.begin() returned false — W5500 not detected.");
    Serial.println("Check MO, MI, SCK, CS, RST, V, G wiring.");
    while (true) delay(1000);
  }

  Serial.println("ETH.begin() OK — waiting for DHCP...");

  unsigned long timeout = millis();
  while (!ethConnected) {
    if (millis() - timeout > 10000) {
      Serial.println("Timeout — no IP received. Check cable and router.");
      while (true) delay(1000);
    }
    delay(100);
  }
}

// ─────────────────────────────────────────────────────────────────
void loop() {
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 5000) {
    lastPrint = millis();
    Serial.print("[");
    Serial.print(millis() / 1000);
    Serial.print("s]  Link: ");
    Serial.print(ethConnected ? "UP" : "DOWN");
    Serial.print("   IP: ");
    Serial.println(ETH.localIP());
  }
}
```
