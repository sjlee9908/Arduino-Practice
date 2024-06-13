//카드, 고리를 대면 UID 출력//
//고리 Card UID:113 239 157 211//
//카드 Card UID:147 197 124 36//

#include <SPI.h>
#include <MFRC522.h>

int RST_PIN=9;
int SS_PIN=10;

MFRC522 mfrc(SS_PIN, RST_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( !mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()){
  delay(500);
  return;
  }
  Serial.print("Card UID:");

  for (byte i=0; i<4; i++){
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
    }
  Serial.println();
}
