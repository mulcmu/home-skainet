# ESPHome merged with ESP-Skainet Speech Commands Recognition Example

This is a work in progress to implement local speech commands in home assistant.  The Espressif ESP32-S3-Korvo-1 developer module includes all hardware necessary to detect a wake word, process preconfigured speech commands, and pass the received commands back to home assistant.  ESPHome was used to build a default configuration for the device to interface with addressable LEDs, push buttons, diagnostic information, and speech commands.   The ESPHome generated source code was merged with the ESP-Skainet en_speech_commands_recognition example code.

**Note: There is a plain ESP32-Korvo-1 with a regular ESP32 MCU not the ESP32S3.  The S3 is required for speech recognition!**

The current project is built using esp-idf 4.4.3 and implements basic functionality for home assistant speech command  processing.  Alexa is configured as the wake word and the 32 speech commands from the example are used for testing.  A binary sensor is activated in home assistant when the wake word is detected and the device is actively listening.  If any of the speech commands are detected with a probability over 50%, the command id number is sent to home assistant to perform the requested action.  After limited testing, the wake word detection works well, the speech command recognition is okay, and the device seems stable (no lockups or reboots).  

Commands from the example are:

```
0,tell me a joke  
1,sing a song  
2,play news channel  
3,turn on my soundbox  
4,turn off my soundbox  
5,highest volume
6,lowest volume
7,increase the volume
8,decrese the volume
9,turn on the tv
10,turn off the tv
11,make me a tea
12,make me a coffee
13,turn on the light
14,turn off the light
15,change the color to red
16,change the color to green
17,turn on all the lights
18,turn off all the lights
19,turn on the air conditioner
20,turn off the air conditioner
21,set the temperature to sixteen degrees
22,set the temperature to seventeen degrees
23,set the temperature to eighteen degrees
24,set the temperature to nineteen degrees
25,set the temperature to twenty degrees
26,set the temperature to twenty one degrees
27,set the temperature to twenty two degrees
28,set the temperature to twenty three degrees
29,set the temperature to twenty four degrees
30,set the temperature to twenty five degrees
31,set the temperature to twenty six degrees
```

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
