int Relaypin = 12; // 변수 Relaypin을 12로 선언, 릴레이
int Switch = 9; // 변수 Switch를 9로 선언, 택트 스위치

void setup() {
  pinMode(Relaypin, OUTPUT); // 디지털 핀 12번을 출력으로 설정
  pinMode(Switch, INPUT_PULLUP); // 디지털 핀 9번을 풀업 입력으로 설정
}

void loop() {
  if (digitalRead(Switch) == LOW) // 스위치가 눌리면
  {
    digitalWrite(Relaypin, HIGH); // 1채널 릴레이 켜짐
    delay(100);
  }
  else
  {
    digitalWrite(Relaypin, LOW); // 1채널 릴레이 꺼짐
    delay(100);
  }
}
