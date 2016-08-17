void Presentazione(){   
  
  // Arduino Symbol
  byte Arduino1[8] = {B00000, B00001, B00011, B00111, B01111, B01100, B11011, B10111};
  byte Arduino2[8] = {B00000, B11111, B11111, B11111, B11111, B01110, B10101, B11011};
  byte Arduino3[8] = {B00000, B10000, B11000, B11100, B11110, B00110, B11011, B11101};
  byte Arduino4[8] = {B10111, B11011, B01100, B01111, B00111, B00011, B00001, B00000};
  byte Arduino5[8] = {B11011, B10101, B01110, B11111, B11111, B11111, B11111, B00000};
  byte Arduino6[8] = {B11101, B11011, B00110, B11110, B11100, B11000, B10000, B00000};
   
  lcd.createChar(1, Arduino1);
  lcd.createChar(2, Arduino2);
  lcd.createChar(3, Arduino3);
  lcd.createChar(4, Arduino4);
  lcd.createChar(5, Arduino5);
  lcd.createChar(6, Arduino6);

  byte posX=2;
  byte posY=1;
  byte Count=1;  
  lcd.clear();
  
  for(byte y=0; y<2; y++){
    for (byte x=0; x<3; x++){
      lcd.setCursor(posX+x,posY+y);
      lcd.write(Count);
      Count++;
      }
  }
 
  display_lcd(posX+5,posY+0,"ARDUINO",0);
  display_lcd(posX+5,posY+1,"Open Source",2000);
  
}

void  PivovarduinoLogo(){
  
  byte Boccale1[8] = {B00000, B00000, B00011, B00011, B00111, B11111, B10011, B10011};
  byte Boccale2[8] = {B00000, B00000, B11111, B11111, B11111, B11111, B11111, B11111};
  byte Boccale3[8] = {B10011, B10011, B10011, B10011, B10011, B11111, B00111, B00011};
  byte Boccale4[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};
  
  lcd.createChar(1, Boccale1);
  lcd.createChar(2, Boccale2);
  lcd.createChar(3, Boccale3);
  lcd.createChar(4, Boccale4);

  byte Count=1;
  byte posX=9;
  byte posY=0;
  lcd.clear();

  for(byte y=0; y<2; y++){
    for (byte x=0; x<2; x++){
      lcd.setCursor(posX+x,posY+y);
      lcd.write(Count);
      Count++;
    }
  }
  display_lcd(4,2,"PivovArduino",0);
  display_lcd(4,3,"versione 0.9",5000);
 // Buzzer(5, 100);
}



