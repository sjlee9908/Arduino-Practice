int latchpin = 8; // 변수 latchpin을 8이라 선언
int datapin = 9; //변수 datapin을 9라 선언
int clockpin = 10; //변수 clockpin을 10이라 선언

void setup() {
  pinMode(latchpin, OUTPUT); // 디지털 핀 8번을 출력으로 설정, 래치 핀 연결
  pinMode(datapin, OUTPUT); // 디지털 핀 9번을 출력으로 설정, 데이터 핀 연결
  pinMode(clockpin, OUTPUT); // 디지털 핀 10번을 출력으로 설정, 클럭 핀 연결
}

void loop() {
  for (int i = 0; i < 8; i++)  { // 74HC595 경우 8비트
    digitalWrite(latchpin, LOW); // latch를 LOW 시켜 데이터를 입력 받음
    shiftOut(datapin, clockpin, LSBFIRST, 1 << i); // dataPin, clockPin 사용,
    digitalWrite(latchpin, HIGH);                 //'LSBFIRST' 왼쪽부터 읽기 (MSBFIRST 오른쪽 부터 읽기)
    delay(150); // LED 속도 조절
  }
}
