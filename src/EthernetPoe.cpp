// Name:     ES3-05  EthernetPoe.cpp
// Updated:  2026-05-27

#include "EthernetPoe.hpp"

byte ethernetMac[] = {0x02, 0x00, 0x02, 0x00, 0x00, 0x03};

EthernetClient ethernetClient;

void ethernetSetup()
{

  Serial.println("Setting up Ethernet...");
// Implementation for Ethernet setup
#ifdef W5500_HARD_RESET
  pinMode(W5500_RST, OUTPUT);
  digitalWrite(W5500_RST, LOW); // needs RST solder bridge closed
  delay(10);
  pinMode(W5500_RST, INPUT);
  delay(250);
#endif

  // Initialize SPI with specified pin configuration
  SPI.begin(W5500_SCK_PIN, W5500_MISO_PIN, W5500_MOSI_PIN, W5500_CS_PIN);

  // Initialize Ethernet using DHCP to obtain an IP address
  Ethernet.init(W5500_CS_PIN);
  if (Ethernet.begin(ethernetMac) == 0)
  {
    Serial.println("Failed to configure Ethernet using DHCP");
    // while (true)
    //   ; // Halt if DHCP configuration fails
  }

  // Print the assigned IP address
  Serial.print("IP Address: ");
  Serial.println(Ethernet.localIP());

  Serial.print("Local Ethernet IP: ");
  Serial.println(Ethernet.localIP());
  Serial.println("Ethernet setup complete.");
}

void ethernetLoop()
{
  // Implementation for Ethernet loop
}

// ### END DBK
