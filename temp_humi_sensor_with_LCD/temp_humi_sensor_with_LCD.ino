//DHT센서에서 받은 값을 LCD로 표시//



#include <SimpleDHT.h>
#include <DHT11.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pin=A2;   
DHT11 dht11(pin); 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int err;
  float temp, humi;
  if((err=dht11.read(humi,temp))==0)
  {
    Serial.println();
    Serial.print("temp:"+(String)temp+"*C");
    Serial.println();
    Serial.print("humi:"+(String)humi+"%");
    delay(1500);
    lcd.setCursor(0,0);
    lcd.print("temp:"+(String)temp+"*C");
    lcd.setCursor(0,1);
    lcd.print("humi:"+(String)humi+"%");
    
    delay(500);
    }
      else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  
}
