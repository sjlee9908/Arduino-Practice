//DHT센서에서 받은 값, uv센서로부터 받은 값을 LCD로 표시(릴레이로 전환)//

//아두이노 GND-브레드보드
//아두이노 5v-브레드보드
//아두이노 3.3v-uv센서
//아두이노 a0-릴레이 공통 신호
//아두이노 a4-lcd sda
//아두이노 a5-lcd scl
//아두이노 9번-브레드보드 스위치
//아두이노 12번- 릴레이 s
//브레드보드 GND-릴레이, lcd, DHT, UV,저항(스위치)
//브레드보드 5v-릴레이, lcd, DHT, UV


int Relaypin=12; //릴레이 신호핀
int Switch=9;    //스위치 핀
int val;         //변수1
int state=0;     //상태
int err;         //변수

#include <SimpleDHT.h>              //라이브러리
#include <DHT11.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pin=A0;                         //릴레이와 연결된 a0
DHT11 dht11(pin);                   //dht센서와 릴레이연결 후 a0연결 

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
  int err;            //변수
  float temp, humi;   //변수
 lcd.clear();         //lcd 지우기
 
 while(state==1){                     //state가 1일때 
      digitalWrite(Relaypin,HIGH);    //릴레이핀 킴
      DHT11 dht11(pin);
      err=dht11.read(humi,temp)==0;   //센서로부터 값 읽기
      Serial.println();               //시리얼 통신
      Serial.print("temp:"+(String)temp+"*C");
      Serial.println();
      Serial.print("humi:"+(String)humi+"%");
      lcd.setCursor(0,0);             //lcd표시
      lcd.print("temp:"+(String)temp+"*C");
      lcd.setCursor(0,1);
      lcd.print("humi:"+(String)humi+"%");
      val=digitalRead(Switch);        //스위치 값읽기
      delay(2500);                    // 2500초 대기 (버튼 중복 입력 방지)
      if (val==LOW){                  //버튼이 눌려졌을 때
        state=0;                     
        break;
        }
      }
 state=0;
      
 delay(2500);
 lcd.clear();

  while(state!=1){                //state가 1이 아닐때(초기값)
    digitalWrite(Relaypin,LOW);   //릴레이 핀 끄기
    int sensorValue;              //센서 변수 설정
    sensorValue = analogRead(0);  //센서 값 읽기
    lcd.setCursor(0,0);           //lcd 표시
    lcd.print("UV Value:");
    lcd.setCursor(9,0);
    lcd.print(sensorValue);
    lcd.setCursor(12,0);
    lcd.print(" ");
    lcd.setCursor(0,1);
    lcd.print(state);
    Serial.println(sensorValue);
    val=digitalRead(Switch);      //스위치 값읽기
    if (val==LOW){
    break;}
    delay(2500);                  //중복입력 방지
 } 
 state=1;
 delay(2500);
}
