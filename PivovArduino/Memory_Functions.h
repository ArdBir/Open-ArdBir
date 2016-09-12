//EEPROM MAP//
/*
  PID MENU
      0       Use Gas
      1       kP
      2       kI
      3       kD
      4       SampleTime
      5       WindowSize
      6       Boil Heat %
      7       Offset
      8       Hysteresi
      9       [ SPACE ]

  UNIT MENU
     10       Scale Temp
     11       Sensor Type
     12       Temp Boil °C
     13       Temp Boil °F
     14       Time Pump Cycle
     15       Time Pump Rest
     16       Pump PreMash
     17       Pump on Mash
     18       Pump on MashOut
     19       Pump on Boil
     20       Temp Pump Rest °C
     21       Temp Pump Rest °F
     22       PID Pipe
     23       Skip Add Malt
     24       Skip Remove Malt
     25       Skip Iodine Test
     26       Iodine Time
     27       Whirlpool
     28 -  31 [ SPACE ]

  RUN  (HTemp °C - LTemp °C - HTemp °F - LTemp °F - Time)
    32 -  36 MashIn
    37 -  41 Fitasi
    42 -  46 Glucanasi
    47 -  51 Proteasi
    52 -  55 B-Amilasi
    57 -  61 A-Amilasi 1
    62 -  66 A-Amilasi 2
    67 -  71 Mash Out

    72       Numbers of Hops
    73       Boil Time
    74       Time Hop  1
    75       Time Hop  2
    76       Time Hop  3
    77       Time Hop  4
    78       Time Hop  5
    79       Time Hop  6
    80       Time Hop  7
    81       Time Hop  8
    82       Time Hop  9
    83       Time Hop 10

    84       FLAG Automode Started

  RESUME
    85       HANDLE Stage
    86       HANDLE Time Rest
    87       Hop Add

    88 -  94 [ SPACE ]

  RECIPE
    95 -  99 Index 1-10
   100 - 151 Recipe Data  1
   152 - 203 Recipe Data  2
   204 - 255 Recipe Data  3
   256 - 307 Recipe Data  4
   308 - 359 Recipe Data  5
   
   360 - 369 Recipe Name  1
   370 - 379 Recipe Name  2
   380 - 389 Recipe Name  3
   390 - 399 Recipe Name  4
   400 - 409 Recipe Name  5
*/

// EEPROM TEST FUNCTIONS //

void readingTest(int sta,int lim){
  int val=0;
  lcd.setCursor(0,1);
  lcd.print("    Reading Test    ");
  delay(2000);
  lcd.clear();
  for(int i = 0; i <=lim; i+=4)
  {
    lcd.setCursor(0,0);
    lcd.print("Address:");
    lcd.setCursor(0,1);
     for (int x=sta; x<i+4 && x<=lim; x++){
      if (x<10) lcd.print(" ");
      lcd.print(x);
      lcd.print("   ");
    }
    lcd.setCursor(0,2);
    lcd.print("Value:");
    lcd.setCursor(0,3);
    for (int x=sta; x<i+4 && x<=lim; x++){
      val=EEPROM.read(x); 
      if (val>=0 && val<10) lcd.print(" ");
      lcd.print(val);
      lcd.print("   ");
    }
    delay(3000);
    lcd.clear();
  }
}

void writingTest(int ini,int fin, int num){
  int val=0;
  lcd.setCursor(0,1);
  lcd.print("    Writing Test    ");
  delay(2000);
  lcd.clear();
  for(int i = ini; i <= fin; i+=4)
  {
    lcd.setCursor(0,0);
    lcd.print("Address:");
    lcd.setCursor(0,1);
     for (int x=i; x<i+4 && x<=fin; x++){
      if (x>=0 && x<10) lcd.print(" ");
      lcd.print(x);
      lcd.print("   ");
    }
    lcd.setCursor(0,2);
    lcd.print("Value:");
    lcd.setCursor(0,3);
    for (int x=i; x<i+4 && x<=fin; x++,num++){
      EEPROM.update(x, num); 
      if (num>=0 && num<10) lcd.print(" ");
      lcd.print(num);
      lcd.print("   ");
    }
    delay(3000);
    lcd.clear();
  }
}

void eepromTest(boolean del) {

  int val=0;
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("     PIVOARDUINO    ");
  lcd.setCursor(0,1);
  lcd.print("     EEPROM TEST    ");
  val=EEPROM.length();
  lcd.setCursor(0,3);
  lcd.print(" Eeprom size: ");
  lcd.setCursor(15,3);
  lcd.print(val);
  delay(4000);
  val=0;

  if (del) EEPROM.clear();
  Buzzer(3, 100);
  lcd.clear();
  writingTest(0,10,0);
  writingTest(11,20,21);
  writingTest(12,12,6);
  readingTest(0,20);
  EEPROM.clear();
}

// Load and save all options from EEPROM //

void EepromLoad(byte memory[]){
  for (int i=0; i<450; i++){
      memory[i]=EEPROM.read(i);
  }
}

void EepromSave(byte memory[]){
  EEPROM.clear();
  for (int i=0; i<450; i++){
      EEPROM.write(i,memory[i]);
  }
}
