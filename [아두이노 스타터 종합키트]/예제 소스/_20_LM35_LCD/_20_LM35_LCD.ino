#include <LiquidCrystal_I2C.h> // lcd 1602 i2c 용 라이브러리 
LiquidCrystal_I2C lcd(0x3F, 16, 2); // 접근주소 : 0x3F or 0x27

float temp;
float sensor;

void setup()
{
  lcd.init();
  lcd.backlight();
}

void loop() {
  sensor = analogRead(A0); // LM35의 온도 센서를 아날로그 핀 0번에 연결
  temp = (sensor * 0.4882815) + 5; // 온도 표시값 계산
  lcd.setCursor(2, 0); // 글자가 출력되는 위치 설정, 2행 0열
  lcd.print("Temperature");
  lcd.setCursor(5, 1); // 5행 1열
  lcd.print(temp); // 측정 온도 표시
  delay(1000);
  lcd.setCursor(10, 1); // 10행 1열
  lcd.print("'C"); // 온도 단위 표시
}

