# ESPHome merged with ESP-Skainet Speech Commands Recognition Example

This is a work in progress to implement local speech commands in home assistant.  The Espressif ESP32-S3-Korvo-1 developer module includes all hardware necessary to detect a wake word, process preconfigured speech commands, and pass the received commands back to home assistant.  ESPHome was used to build a default configuration for the device to interface with addressable LEDs, push buttons, diagnostic information, and speech commands.   The ESPHome generated source code was merged with the ESP-Skainet en_speech_commands_recognition example code.

**Note: There is a plain ESP32-Korvo-1 with a regular ESP32 MCU not the ESP32S3.  The S3 is required for speech recognition!**

The current project is built using esp-idf 4.4.3 and implements basic functionality for home assistant speech command  processing.  Alexa is configured as the wake word and the 32 speech commands from the example are used for testing.  A binary sensor is activated in home assistant when the wake word is detected and the device is actively listening.  If any of the speech commands are detected with a probability over 50%, the command id number is sent to home assistant to perform the requested action.  After limited testing, the wake word detection works well, the speech command recognition is okay, and the device seems stable (no lockups or reboots).  

Commands are hardcoded in the  sdkconfig file.  Currently set to:

| Command ID | Phrase                      | International phonetic alphabet |
| ---------- | --------------------------- | ------------------------------- |
| 0          | zero                        | "ZgRb"                          |
| 1          | one                         | "WcN"                           |
| 2          | two                         | "To"                            |
| 3          | three                       | "vRm"                           |
| 4          | four                        | "FeR"                           |
| 5          | five                        | "FiV"                           |
| 6          | six                         | "SgKS"                          |
| 7          | seven                       | "SfVcN"                         |
| 8          | eight                       | "dT"                            |
| 9          | nine                        | "NiN"                           |
| 10         | turn off  upstairs lights   | "TkN eF  cPSTfRZ LiTS"          |
| 11         | turn off  downstairs lights | "TkN eF  DtNSTfRZ LiTS"         |
| 12         | turn off  outside lights    | "TkN eF  tTSiD LiTS"            |
| 13         | turn off  basement lights   | "TkN eF  BdSMcNT LiTS"          |
| 14         | turn off tv                 | "TkN eF  TmVm"                  |
| 15         | turn off roku               | "TkN eF  RbKo"                  |
| 16         | make me a  sandwich         | "MdK Mm  c SaNDWgp"             |
| 17         | dock the  automower         | "DnK jc  eTcMtk"                |
| 18         | resume  automower schedule  | "RmZoM  eTcMtk SKfqwL"          |
| 19         | start netflix               | "STnRT  NfTFLgKS"               |
| 20         | start pandora               | "STnRT  PaNDeRc"                |

## TODO:

Add some links and pictures to readme.

Addressable LEDs are controlled by the en_speech_commands_recognition sample code.  Use the ESPHome light control to control color and brightness.  Still have an animation for wake word / listening detected.

Cleanup compile warnings.

ESP32-S3-Korvo-1 has a mono speaker.  Provide audio feedback for wake word and maybe media player support.

Design a 3d printed case.

Add support for ESP32-S3-BOX or Korvo-2.

Add support to dynamically change speech recognition commands from HA.  Provide a binary for easier installation.

## Build steps:

Starting with a fresh Ubuntu virtual machine, update and install dependencies.

```
sudo apt update
sudo apt upgrade

sudo apt-get install git wget flex bison gperf python3 python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0 python3-pip
```

Clone the Espressif esp-skainet github repository.

```
mkdir -p ~/esp
cd ~/esp
git clone --recursive https://github.com/espressif/esp-skainet.git
```

Update the integral esp-idf to version 4.4.2 (4.4 is standard but the ADC doesn't work, 4.4.3 Audio out doesn't work)

```
cd ~/esp/esp-skainet/esp-idf/
git fetch
git checkout v4.4.2
git submodule update --init --recursive
```

Install esp-idf

```
cd ~/esp/esp-skainet/esp-idf
./install.sh all
. ./export.sh
```

Try building an example and flashing to test environment setup.

```
cd ~/esp/esp-skainet/examples/en_speech_commands_recognition/
idf.py set-target esp32s3
idf.py menuconfig
  [change wakeword to alexa in menu system]
idf.py build
  [build command provides the command necessary to flash]
```

Install home-skainet

```
cd ~/esp/esp-skainet/examples
git clone https://github.com/mulcmu/home-skainet.git
```

Edit secrets.h with your wifi credentials.

Edit esphome.cpp line 256 with static IP address for your router.

Build and flash

```
idf.py build
```

## Contributions:

Contributions and feedback welcome.
