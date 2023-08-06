
// Library can be downloaded from : https://github.com/prasanpro/ProgrammingArduino30Days/blob/main/Chapter6/ArduinoRTClibrary-master.zip
#include <virtuabotixRTC.h> //Library used

//CLK -> 4 , DAT -> 3, Reset -> 2

virtuabotixRTC myRTC(4, 3, 2); //If you change the wiring change the pins here also

void setup() {
 Serial.begin(9600);

// Set the current date, and time in the following format:
 // seconds, minutes, hours, day of the week, day of the month, month, year
 //myRTC.setDS1302Time(00, 46, 22, 0, 6, 8, 2023); //Here you write your actual time/date as shown above 
 //but remember to "comment/remove" this function once you're done
 //The setup is done only one time and the module will continue counting it automatically
}

void loop() {
 // This allows for the update of variables for time or accessing the individual elements.
 myRTC.updateTime();
 
// Start printing elements as individuals
 Serial.print("Current Date / Time: ");
 updateDOWDisplay();
 Serial.print("  ");
 Serial.print(myRTC.dayofmonth); //You can switch between day and month if you're using American system
 Serial.print("/");
 Serial.print(myRTC.month);
 Serial.print("/");
 Serial.print(myRTC.year);
 Serial.print(" ");
 Serial.print(myRTC.hours);
 Serial.print(":");
 Serial.print(myRTC.minutes);
 Serial.print(":");
 Serial.println(myRTC.seconds);

// Delay so the program doesn't print non-stop
 delay(1000);
}

// Function to map day of week with week name, week starts with Sunday
void updateDOWDisplay()
{
  int dow = myRTC.dayofweek;  // Get the day of week nr right now and store them in an integer called dow
  switch(dow){
     case 1:
     Serial.print("Mon");
     break;
     case 2:
     Serial.print("Tue");
     break;
     case 3:
     Serial.print("Wed");
     break;
     case 4:
     Serial.print("Thu");
     break;
     case 5:
     Serial.print("Fri");
     break;
     case 6:
     Serial.print("Sat");
     break;
     case 0:
     Serial.print("Sun");
     
     break;}
}
