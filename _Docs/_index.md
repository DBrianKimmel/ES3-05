# ES3-05

[Back](../../../_Docs/_index.md)

Waveshare ESP32-S3-ETH development board with Waveshare PoE Module (B) daughterboard

Uses Espressif ESP32-S3 SOC

Has onboard RGB neopixel led.
Has onboard Ethernet connection.
Has daughterboard POE extractor.
Has onboard TF card connection (Micro SD card).
Has onboard 2 pushbutton switches.
Has onboard 2 status leds.
Has OV5640 camera connector.
Has pico compatible header.
Has 25 GPIO pins

Uses Wiznet W5500 Ethernet chip

Regarding the informations from
    [here 1](https://www.waveshare.com/esp32-s3-eth.htm) and
    [here 2](https://www.waveshare.com/wiki/ESP32-S3-ETH)
 it is an ESP32-S3 with internal 8MB Octal PRSAM and external 16 MB quad Flash.

So these settings should work for you:

```ini
[env:esp32-s3-devkitc-1]
platform = espressif32
board = esp32-s3-devkitc-1
framework = arduino

board_build.arduino.memory_type = qio_opi
board_build.flash_mode = qio
board_build.psram_type = opi
board_upload.flash_size = 16MB
board_upload.maximum_size = 16777216
board_build.partitions = default_16MB.csv
board_build.extra_flags =
  -DBOARD_HAS_PSRAM
  -DARDUINO_USB_CDC_ON_BOOT=1
```

## EspConnect

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

### Partitions

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

## WiFi

* IEEE 802.11b/g/n-compliant
* Supports 20 MHz, 40 MHz bandwidth in 2.4 GHz band
* 1T1R mode with data rate up to 150 Mbps
* Wi-Fi Multimedia (WMM)
* TX/RX A-MPDU, TX/RX A-MSDU
* Immediate Block ACK
* Fragmentation and defragmentation
* Automatic Beacon monitoring (hardware TSF)
* 4 × virtual Wi-Fi interfaces
* Simultaneous support for Infrastructure BSS in Station, SoftAP, or Station + SoftAP modes
    Note that when ESP32-S3 scans in Station mode, the SoftAP channel will change along with the Station channel
* Antenna diversity
* 802.11mc FTM

## Bluetooth

* Bluetooth LE: Bluetooth 5, Bluetooth mesh
* High power mode (20 dBm)
* Speed: 125 Kbps, 500 Kbps, 1 Mbps, 2 Mbps
* Advertising extensions
* Multiple advertisement sets
* Channel selection algorithm #2
* Internal co-existence mechanism between Wi-Fi and Bluetooth to share the same antenna

## Goals

1. get a basic system to build, upload, run and Produce progress information on a monitor and in logs.

## References

* [1](https://www.waveshare.com/wiki/ESP32-S3-ETH)
* [2](https://docs.platformio.org/en/latest/projectconf/index.html)
* [3](https://docs.platformio.org/en/latest/platforms/espressif32.html#configuration)
* [Unit Testing](https://docs.platformio.org/en/latest/advanced/unit-testing/introduction.html)
* [What is PlatformIO]()
* [PlatformIO Project Examples](https://github.com/platformio/platformio-examples)
* [S3](https://www.circuitstate.com/tutorials/getting-started-with-esp32-s3-wi-fi-bluetooth-soc-using-esp32-s3-dev-kit-nxr8/)
