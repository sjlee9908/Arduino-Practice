int Buzzer_Pin = 5; // 변수 Buzzer_Pin을 5라 선언
int i ; // 정수형 변수 i를 선언

void setup() {
  pinMode(Buzzer_Pin, OUTPUT); // 디지털 핀 5번을 출력으로 설정
}

void loop() {
  for (i = 15; i >= 1; i--) { // 점점 빨라지는 박자의 소리를 만듬
    digitalWrite(Buzzer_Pin, HIGH);
    delay(10 * i);
    digitalWrite(Buzzer_Pin, LOW);
    delay(50);
  }
}
