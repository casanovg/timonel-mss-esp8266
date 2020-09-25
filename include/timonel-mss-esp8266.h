/*
  Timonel bootloader I2C-master single slave application demo for ESP8266
  ............................................................................
  File: timonel-mss-esp8266.h (Header)
  ............................................................................
  This demo implements an I2C serial commander to control interactively a
  Tiny85 microcontroller running the Timonel bootloader from an ESP8266
  master. It uses a serial console configured at 115200 N 8 1 for feedback.
  ............................................................................
  Version: 1.5.1 / 2020-09-25 / gustavo.casanova@nicebots.com
  ............................................................................
*/

#ifndef TIMONEL_MSS_ESP8266_H
#define TIMONEL_MSS_ESP8266_H

#include <NbMicro.h>
#include <TimonelTwiM.h>
#include <TwiBus.h>

// This software
#define VER_MAJOR 1
#define VER_MINOR 5
#define VER_PATCH 1

// Serial display settings
#define USE_SERIAL Serial
#define SERIAL_BPS 115200

// I2C pins
#define SDA 2  // I2C SDA pin - ESP8266 2 - ESP32 21
#define SCL 0  // I2C SCL pin - ESP8266 0 - ESP32 22

// Upper EEPROM memory location
#define EEPROM_TOP 0x1FF
// Rotating bar delay
#define ROTATION_DLY 60
// Application mode switch delay
#define MODE_SWITCH_DLY 250

// Prototypes
void setup(void);
void loop(void);
void ReadChar(void);
uint16_t ReadWord(void);
uint8_t DiscoverDevice(bool *p_app_mode, const uint8_t sda = 0, const uint8_t scl = 0);
Timonel::Status PrintStatus(Timonel *timonel);
void ShowHeader(const bool app_mode);
void ShowMenu(const bool app_mode);
void ClrScr(void);
void PrintLogo(void);
void RotaryDelay(void);
void RotatingBar(uint8_t *rotary_state);

#endif  // TIMONEL_MSS_ESP8266_H
