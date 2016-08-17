// sensor and lcd
OneWire ds(7);
LiquidCrystal lcd(A4, A5, 2, 3, 4, 5);

// push buttons
const char Button_up    = A0;
const char Button_dn    = A2;
const char Button_enter = A3;
const char Button_start = A1;

// outputs
const byte Pump = 6;
const byte Buzz = 8;
const byte Heat = 9;

