#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

float temp;
float sensor;


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  sensor = analogRead(A0);
  temp = (sensor * 0.4882815)+5;
  lcd.setCursor(2,0);
  lcd.print("Temperature");
  lcd.setCursor(5,1);
  lcd.print(temp);
  delay(1000);
  lcd.setCursor(10,1);
  lcd.print("'C");

}
