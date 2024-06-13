int led = 13; // 변수 led를 13으로 선언, LED
int buzzer = 6; // 변수 buzzer를 6으로 선언, buzzer
int flame = A0; //변수 flame을 A0로 선언, 불꽃 감지 센서
int state = 0; // 변수 state를 0으로 선언, 상태 값 저장 변수

void setup() {
  pinMode(led, OUTPUT); // 디지털 13번 핀을 출력으로 설정
  pinMode(buzzer, OUTPUT);
  pinMode(flame, INPUT); // 아날로그 핀 0번을 불꽃 감지 센서 입력으로 설정
  Serial.begin(9600); // 시리얼 통신 속도 9600
}

void loop() {
  state = analogRead(flame); // 불꽃 감지 센서 값을 입력받음

  digitalWrite(led, LOW); // 초기 LED값 off
  noTone(buzzer); // 초기 부저 off

  if (state == 0) { // 불꽃 감지 센서의 입력 값이 0일 때
    Serial.println("OFF"); // 시리얼 모니터에 OFF 출력
    digitalWrite(led, LOW); // LED 꺼짐
    noTone(buzzer); // 부저 안울림
  }
  else { // 불꽃 감지 센서에 0이 아닌 작은 입력이라도 생긴다면
    Serial.println("ON"); // 시리얼 모니터에 ON을 출력
    digitalWrite(led, HIGH); // LED 켜짐
    tone(buzzer, 500, 100); // 부저 울림
  }
  delay(100);
}
