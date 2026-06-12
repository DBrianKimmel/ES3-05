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

## Git

```txt
git remote add origin https://github.com/DBrianKimmel/ES3-05.git

# Verify remote is added
git remote -v
# You should see:
#    origin  https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git (fetch)
#    origin  https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git (push)

# Check current branch
git branch
# Rename to main if it is not main already (github uses main)
git branch -M main

# Push your code
git push -u origin main
# The -u flag sets up tracking between your local main branch and the remote main branch.


```

## References

* [1](https://www.waveshare.com/wiki/ESP32-S3-ETH)
* [2](https://docs.platformio.org/en/latest/projectconf/index.html)
* [3](https://docs.platformio.org/en/latest/platforms/espressif32.html#configuration)
* [Unit Testing](https://docs.platformio.org/en/latest/advanced/unit-testing/introduction.html)
* [What is PlatformIO]()
* [PlatformIO Project Examples](https://github.com/platformio/platformio-examples)
* [S3](https://www.circuitstate.com/tutorials/getting-started-with-esp32-s3-wi-fi-bluetooth-soc-using-esp32-s3-dev-kit-nxr8/)
* [Dronebot](https://dronebotworkshop.com/esp32-ethernet/)
