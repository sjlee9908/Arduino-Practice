#include <SPI.h>
#include <MFRC522.h>

int RST_PIN = 9 ; // 변수 RST_PIN을 9로 선언, reset 핀
int SS_PIN = 10 ; // 변수 SS_PIN을 10으로 선언, 데이터를 주고 받는 핀(SS = Slave Selector)

MFRC522 mfrc(SS_PIN, RST_PIN); // MFR522를 이용하기 위해 mfrc객체 생성

void setup() {
  Serial.begin(9600); // 시리얼 통신 속도 9600
  SPI.begin(); // SPI 초기화 (하나의 master와 다수의 slave의 통신 방식)
  mfrc.PCD_Init();
}

void loop() {
  //태그 접촉이 없음 혹은 ID가 읽히지 않음
  if ( !mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()) {
    delay(500); // 0.5초의 딜레이
    return;
  }
  Serial.print("Card UID: "); // 태그의 ID 출력

  for (byte i = 0; i < 4; i ++) { // 태그의 ID출력을 ID사이즈 4 까지 반복
    Serial.print(mfrc.uid.uidByte[i]); // mfrc.uid.uidByte[0] ~ mfrc.uid.uidByte[3]까지 출력
    Serial.print(" "); // id 사이의 간격 출력
  }
  Serial.println();
}
