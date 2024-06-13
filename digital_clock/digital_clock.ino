//디지털 시계//

#include <virtuabotixRTC.h>
#include <LiquidCrystal_I2C.h>


#define PIN_RTC_CLK  5
#define PIN_RTC_DATA 6
#define PIN_RTC_RST  7

LiquidCrystal_I2C lcd(0x27,16,2);

int _day       =23,
    _month     =2,
    _year      =2019,
    _dayofweek =5,
    _hour      =12,
    _minute    =10,
    _seconds   =15
    ;
    
virtuabotixRTC myRTC(PIN_RTC_CLK, PIN_RTC_DATA,PIN_RTC_RST);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myRTC.setDS1302Time(_seconds, _minute,_hour,_dayofweek,_day,_month,_year);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  myRTC.updateTime();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" ");
  imprime_dia_da_semana(myRTC.dayofweek);
  lcd.print(", ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  lcd.print(" ");
  lcd.setCursor(3,1);
  lcd.print(" ");

  if (myRTC.hours<10){
    lcd.print("0");
    }
    lcd.print(myRTC.hours);
    lcd.print(":");

  if (myRTC.minutes<10){
    lcd.print("0");
    }
    lcd.print(myRTC.minutes);
    lcd.print(":");
 
  if (myRTC.seconds<10){
    lcd.print(" ");
    }
    lcd.print(myRTC.seconds);

    delay(1000);
}


void imprime_dia_da_semana(int dia)
{
  switch (dia)
  {
    case 1:
    lcd.print("MON");
    break;
    case 2:
    lcd.print("TUE");
    break;
    case 3:
    lcd.print("WED");
    break;
    case 4:
    lcd.print("THU");
    break;
    case 5:
    lcd.print("fri");
    break;
    case 6:
    lcd.print("SAT");
    break;
    case 7:
    lcd.print("SUN");
    break;
    }
  
  
  }
