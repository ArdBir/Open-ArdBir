#include <LiquidCrystal_I2C.h>
#include <CurieEEPROM.h>

// sensor and lcd
OneWire ds(7);
LiquidCrystal_I2C lcd(0x3F,20,4); 

// push buttons
const char Button_up    = A0;
const char Button_dn    = A2;
const char Button_enter = A3;
const char Button_start = A1;

// outputs
const byte Pump = 6;
const byte Buzz = 8;
const byte Heat = 9;
