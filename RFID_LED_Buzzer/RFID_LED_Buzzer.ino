//고리를 대면 통과, 다른 것을 대면 통과x//

#include <SPI.h>
#include <MFRC522.h>

int RST_PIN=9;
int SS_PIN=10;
MFRC522 mfrc(SS_PIN, RST_PIN);

int LED_G=3;
int LED_R=4;
int buzzer=6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();
  pinMode(LED_G,OUTPUT);
  pinMode(LED_R,OUTPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if ( !mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()){
  delay(500);
  return;
  }
  if (mfrc.uid.uidByte[0]==113 && mfrc.uid.uidByte[1]==239 &&
  mfrc.uid.uidByte[2]==157 && mfrc.uid.uidByte[3]==211){
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_R,LOW);
    Serial.println();
    Serial.print("Welcome");
    
    tone(buzzer,523,100);
    delay(500);
    }
    else{
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_R,HIGH);
    Serial.println();
    Serial.print("Access Denied");
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
    tone(buzzer,523,100);
    delay(500);
      }
}
