//DHT센서에서 받은 값을 LCD로 표시//
int Relaypin=12;
int Switch=9;
int val=0;
int state=0;


#include <SimpleDHT.h>
#include <DHT11.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pin=A0;   
DHT11 dht11(pin); 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  pinMode(Relaypin,OUTPUT);
  pinMode(Switch,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int err;
  float temp, humi;
 val=digitalRead(Switch);

 
 if (val==LOW)
  {
    state=1-state;
    }
  if (state==1)
    {
      digitalWrite(Relaypin,HIGH);
      delay(1000);
      }
 if (state!=1){
  digitalWrite(Relaypin,LOW);
  delay(1000);
  }

  
  if(((err=dht11.read(humi,temp))==0)and(state==1))
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
    
 if (val==LOW)
  {
    state=1-state;
    }
  if (state==1)
    {
      digitalWrite(Relaypin,HIGH);
      delay(1000);
      }
 if (state!=1){
  digitalWrite(Relaypin,LOW);
  delay(1000);
  }

    
}
