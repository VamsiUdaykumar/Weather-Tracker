
#include "dht.h"

#define dht_dpin A0 //no ; here. Set equal to channel sensor is on
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 10, 5, 4, 3, 2);
dht DHT;

void setup(){
  Serial.begin(9600);
  delay(300);//Let system settle
  lcd.begin(16,2);
 
  delay(700);//Wait rest of 1000ms recommended delay before
  //accessing sensor
}//end "setup()"

void loop(){
  //This is the "heart" of the program.
  DHT.read11(dht_dpin);
   lcd.setCursor(0,0);

    lcd.print("Humidity = ");
    lcd.print(DHT.humidity);
    lcd.print("%  ");
    lcd.setCursor(0,1);
    lcd.print("temp = ");
    lcd.print(DHT.temperature); 
    lcd.print("C  ");
    delay(1500);
    lcd.noDisplay();
    delay(800);
    lcd.setCursor(0,0);
    lcd.print("Pressure = 1 atm");
    
    lcd.display();
  delay(1500);//Don't try to access too frequently... in theory
  //should be once per two seconds, fastest,
  //but seems to work after 0.8 second.
}// end loop()


