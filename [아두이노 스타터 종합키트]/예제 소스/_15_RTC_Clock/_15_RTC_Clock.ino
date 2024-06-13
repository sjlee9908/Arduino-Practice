#include <virtuabotixRTC.h>
#include <LiquidCrystal_I2C.h>

#define PIN_RTC_CLK   5 //각각의 변수들을 정의합니다.
#define PIN_RTC_DATA  6
#define PIN_RTC_RST   7

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD의 주소값(0x3F 또는 0x27)

// 현재 시간 및 날짜를 입력합니다.
int _day        = 22,
    _month      = 2,
    _year       = 2019,
    _dayofweek  = 5,
    _hour       = 11,
    _minutes    = 44,
    _seconds    = 35
                  ;

virtuabotixRTC myRTC(PIN_RTC_CLK, PIN_RTC_DATA, PIN_RTC_RST);

void setup() {
  Serial.begin(9600);

  // LCD에 출력할 변수들
  myRTC.setDS1302Time(_seconds, _minutes, _hour, _dayofweek, _day, _month, _year);
  lcd.init();
  lcd.backlight();
}

void loop() {
  myRTC.updateTime();

  lcd.clear();
  lcd.setCursor(0, 0); // LCD 위치 설정
  lcd.print(" ");
  imprime_dia_da_semana(myRTC.dayofweek);
  lcd.print(", ");
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  lcd.print("  ");
  lcd.setCursor(3, 1);
  lcd.print(" ");

  if (myRTC.hours < 10) {
    lcd.print("0");
  }
  lcd.print(myRTC.hours);
  lcd.print(":");

  if (myRTC.minutes < 10) {
    lcd.print("0");
  }
  lcd.print(myRTC.minutes);
  lcd.print(":");

  if (myRTC.seconds < 10)
  {
    lcd.print(" ");
  }
  lcd.print(myRTC.seconds);

  delay(1000);
}

void imprime_dia_da_semana(int dia) // 요일 설정
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
      lcd.print("FRI");
      break;
    case 6:
      lcd.print("SAT");
      break;
    case 7:
      lcd.print("SUN");
      break;
  }
}
