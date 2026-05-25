# EspConnect

ESP32-S3 (QFN56) (revision v0.2)  ESP32-S3  v0.2  3c:0f:02:de:59:94 (MAC)

 Flash & Clock
16MB
Crystal 40 MHz
CPU Cores : 2 (Dual)
Max CPU Frequency : 240 MHz
Embedded PSRAM : 8MB (AP Memory 3.3 V)

 Feature Set
5 capabilities: Wi-Fi  BLE  Dual Core  240 MHz  Embedded PSRAM 8MB (AP Memory 3.3 V)

 Package & Revision
Chip Variant: ESP32-S3 (QFN56)
Package Form Factor: 56-pin QFN (7 mm x 7 mm)
Revision: v0.2
Max CPU Frequency: 240 MHz
CPU Cores: 2 (Dual)

 Embedded Memory
Embedded PSRAM: 8MB (AP Memory 3.3 V)
Flash ID: 0x184020
Flash Manufacturer: Micron / Numonyx (0x20)
Flash Device: 16 MB

 Security
eFuse Block Version: v1.3
Flash Encryption: disabled
Flash Encryption Details: FLASH_CRYPT_CNT=0x0 (set bits=0)
Flash Encryption Mode: XTS AES (supported on this chip)
Secure Boot: disabled
Secure Boot Type: v2 (digest-based, supports revocation)
JTAG Protection: enabled
USB Protection: enabled
Security Note: ESP32-S3 supports XTS encryption, HMAC key slots, and flexible key purposes.

 Peripherals
PWM/LEDC: 8 channels · 4 timers · Single LEDC group.

 Connection
USB Bridge: Espressif Systems - ESP32 Native USB (0x1001)
Connection Baud: 921,600 bps

## Partitions

Partitions — 16MB
Partitions use 3.96 MB    Unused flash detected - about 12 MB (12,582,912 bytes) is reclaimable.

Label             Type                subtype             offset      size
Bootloader        Reserved            Reserved            0x0         32 KB
Partition Table   Reserved            Reserved            0x8000      4 KB
nvs               Data (0x01)         NVS (0x02)          0x9000      20 KB
otadata           Data (0x01)         OTA Data (0x00)     0xE000      8 KB
app0              Application (0x00)  OTA 0 (0x10)        0x10000     3 MB
spiffs            Data (0x01)         SPIFFS (0x82)       0x310000    896 KB
coredump          Data (0x01)         Core Dump (0x03)    0x3F0000    64 KB
