#include <DHT.h>
#include <LiquidCrystal_I2C.h> 
 LiquidCrystal_I2C lcd(0x27,16,2); 
#define Type DHT11
int sensepin = 2; 
int dig_rain= 8; 
 int value;  
float temp; 
float Humidity; 
DHT ht(sensepin,Type); 

void setup() {
ht.begin(); 
delay(1000); 

  // put your setup code here, to run once:
lcd.init(); 
  // pinMode(dig_rain,INPUT); 
lcd.backlight(); 
lcd.clear(); 
}

void loop() {
  // put your main code here, to run repeatedly:
value = digitalRead(dig_rain); 
  temp = ht.readTemperature(); 
  Humidity = ht.readHumidity(); 
lcd.setCursor(0,0);
lcd.print("Temp:") ;
lcd.print(temp);
lcd.print(" C"); 
lcd.setCursor(0,1); 
lcd.print("Humidity:"); 
lcd.print(Humidity); 
delay(5000); 
lcd.clear();
if(value)
  {
       lcd.print("Weather is clear"); 
   delay(2000); 
   }
 else 
 {
   lcd.print("it's Raining "); 
      delay(2000); 
 }
delay(500); 
lcd.clear(); 
delay(2000); 
}