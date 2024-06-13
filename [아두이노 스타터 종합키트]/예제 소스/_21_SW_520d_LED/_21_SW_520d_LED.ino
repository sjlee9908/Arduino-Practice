int SW; // 정수형 변수 SW를 선언
int led_r = 7; // 변수 led_r을 7이라 선언
int led_b = 6; // 변수 led_b를 6이라 선언

void setup() {
  Serial.begin(9600); // 시리얼 통신 속도 초기화
  pinMode(led_r, OUTPUT); // 디지털 핀 7번을 출력으로 설정
  pinMode(led_b, OUTPUT); // 디지털 핀 6번을 출력으로 설정
}

void loop() {
  SW = analogRead(A1); // 아날로그 핀 A1에 연결된 기울기 센서 값을 SW에 저장

  if (SW >= 200) { // SW가 200 이상일 때
    digitalWrite(led_r, HIGH);
    digitalWrite(led_b, LOW);
    Serial.println(SW);
    delay(300);
  }
  else { // SW가 200 미만일 때
    digitalWrite(led_b, HIGH);
    digitalWrite(led_r, LOW);
    Serial.println(SW);
    delay(300);
  }
}
