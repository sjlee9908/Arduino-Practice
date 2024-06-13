int Buzzer_Pin = 5; // 부저의 +측에 연결된 핀

int Tones[8] = {261, 294, 330, 349, 392, 440, 494, 523};
int Tones_Number; // Tones에 들어갈 변수

void setup() {

}

void loop() {
  /*도 레 미 파 솔 라 시 도를 연속적으로 연주한다.*/
  for (Tones_Number = 0; Tones_Number < 8; Tones_Number++) {
    tone(Buzzer_Pin, Tones[Tones_Number]); // tone(출력 핀 번호, 주파수 값)
    delay(500);
  }
  noTone(Buzzer_Pin);
  delay(1000);
}

