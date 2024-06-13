int LED = 9; // 변수 LED 를 9로 선언

void setup() {
  Serial.begin(9600); // 시리얼 통신 초기화
  pinMode(LED, OUTPUT); // 9번 핀을 출력으로 설정
}

void loop() {
  int val = analogRead(A0); // 변수 val 값을 아날로그 핀 5에서 읽은 값(max = 1024) / 4 (max = 255)
  Serial.println(val); // 시리얼 모니터로 가변저항 값을 출력
  analogWrite(LED, val); // 가변 저항의 값을 LED(9번 핀)으로 보내 출력
}
