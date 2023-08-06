
#include <Wire.h>
#include <virtuabotixRTC.h> //Libraries needed
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//CLK -> 6 , DAT -> 7, Reset -> 8

virtuabotixRTC myRTC(4, 3, 2); //If you change the wiring change the pins here also


void setup() {
 lcd.init();
 lcd.clear();          
 lcd.backlight();
 lcd.setCursor(4,0); 
 lcd.print("Arduino");
 lcd.setCursor(2,1);
 lcd.print("Digital Clock");
 
 //myRTC.setDS1302Time(15, 31, 15, 5, 12, 1, 2018); //Here you write your actual time/date as shown above 
 //but remember to "comment/remove" this function once you're done as I did
 //The setup is done only one time and the module will continue counting it automatically
 delay(2000);
}

void loop() {
 lcd.clear(); //Here after clearing the LCD we take the time from the module and print it on the screen with usual LCD functions
 myRTC.updateTime();
 updateDOWDisplay();
 lcd.setCursor(6,0);  // Move the cursor to column six, first row
 lcd.print(myRTC.dayofmonth);
 lcd.print("/");
 lcd.print(myRTC.month);
 lcd.print("/");
 lcd.print(myRTC.year);
 lcd.setCursor(4,1);   // Move the cursor to column four, second row
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.print(myRTC.seconds);
 delay(1000);
}

void updateDOWDisplay()
{
  int dow = myRTC.dayofweek; // Get the day of week nr right now and store them in an integer called dow
  lcd.setCursor(1, 0);       // Move the cursor to column one, first row
  switch(dow){
     case 1:
     lcd.print("Mon");
     break;
     case 2:
     lcd.print("Tue");
     break;
     case 3:
     lcd.print("Wed");
     break;
     case 4:
     lcd.print("Thu");
     break;
     case 5:
     lcd.print("Fri");
     break;
     case 6:
     lcd.print("Sat");
     break;
     case 0:
     lcd.print("Sun");
     
     break;}
}
