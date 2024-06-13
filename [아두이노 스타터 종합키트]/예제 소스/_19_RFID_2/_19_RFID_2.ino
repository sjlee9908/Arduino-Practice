#include <SPI.h>
#include <MFRC522.h>

int RST_PIN = 9; // 변수 RST_PIN을 9로 선언, reset 핀
int SS_PIN = 10; // 변수 SS_PIN을 10으로 선언, 데이터를 주고 받는 핀(SS = Slave Selector)

MFRC522 mfrc(SS_PIN, RST_PIN); // MFR522를 이용하기 위해 mfrc객체 생성

int LED_G = 3; // 변수 LED_G를 3으로 선언, 녹색 LED
int LED_R = 4; // 변수 LED_R을 4로 선언, 빨간색 LED
int buzzer = 6; // 변수 buzzer를 6으로 선언, 부저 제어

void setup() {
  Serial.begin(9600); // 시리얼 통신 속도 9600
  SPI.begin(); // SPI 초기화 (하나의 master와 다수의 slave의 통신 방식)

  mfrc.PCD_Init();
  pinMode(LED_G, OUTPUT); // 디지털 핀 3번을 출력으로 설정
  pinMode(LED_R, OUTPUT); // 디지털 핀 4번을 출력으로 설정
  pinMode(buzzer, OUTPUT); // 디지털 핀 6번을 출력으로 설정
}

void loop() {
  // 태그 접촉이 없음 혹은 ID가 읽히지 않음
  if ( !mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()) {
    delay(500); // 0.5초의 딜레이
    return;
  }

  if (mfrc.uid.uidByte[0] == 35 && mfrc.uid.uidByte[1] == 54
      && mfrc.uid.uidByte[2] == 22 && mfrc.uid.uidByte[3] == 137) { // 지정된 카드의 고유 ID
    digitalWrite(LED_G, HIGH);  // 3번 핀에 연결된 LED ON
    digitalWrite(LED_R, LOW); // 4번 핀에 연결된 LED OFF
    Serial.println("Hello, Eduino!"); // 시리얼 모니터에 Hello, Eduino! 출력
    tone(buzzer, 523 , 100);
    delay(500);
  }
  else { // 다른 태그의 ID일 경우
    digitalWrite(LED_G, LOW);  // 3번 핀에 연결된 LED OFF
    digitalWrite(LED_R, HIGH); // 4번 핀에 연결된 LED ON
    Serial.println("Who are you?"); // 시리얼 모니터에 Who are you? 출력
    tone(buzzer, 523, 100);
    delay(500);
    tone(buzzer, 523, 100);
    delay(500);
  }
}
