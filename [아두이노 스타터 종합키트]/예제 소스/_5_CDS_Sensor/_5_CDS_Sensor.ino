int cds = A1; // 변수 cds를 A1이라 선언
int LED = 8; // 변수 LED를 8이라 선언

void setup() {
  Serial.begin(9600);
  pinMode(cds, INPUT); // 아날로그 핀 A1이 입력
  pinMode(LED, OUTPUT); // 디지털 핀 8이 출력
}

void loop() {
  int val = analogRead(cds); // 변수 val은 아날로그 핀 A1에서 읽어들이는 값
  Serial.print("cds_sensor : ");
  Serial.println(val); // 변수 val의 값을 Serial 출력

  if (val > 900) { // val값이 900이 넘는다면, 디지털 핀 9번에 연결된 LED가 점등
    digitalWrite(LED, HIGH);
    Serial.println("LED ON"); // 시리얼 모니터에 LED ON이 출력
  }
  else { // val값이 900이 안된다면, 디지털 핀 9번에 연결된 LED가 소등
    digitalWrite(LED, LOW);
    Serial.println("LED OFF"); // 시리얼 모니터에 LED OFF가 출력
  }
  delay(200);
}
