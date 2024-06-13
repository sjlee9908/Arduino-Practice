int soundSensor = A0; // 변수 soundSensor를 A0로 선언
int led[6] = {8, 9, 10, 11, 12, 13}; // led[] 배열에 8에서 13까지의 변수를 선언
int threshold = 500; // 변수 threshold에 500을 선언, 감도 조절
int count = 0; // 변수 count를 0으로 선언, 박수의 숫자
void setup() {
  Serial.begin(9600); // 시리얼모니터 출력
  pinMode(soundSensor, INPUT); // 사운드 센서가 연결된 아날로그 핀 0번을 입력으로 설정
  for (int i = 0; i < 6; i++) // 디지털 핀 8번에서 13번까지를 출력으로 설정
    pinMode(led[i], OUTPUT);
}
void loop() {
  if ( analogRead(soundSensor) >= threshold) { // 감지된 소리의 크기가 500 이상일때
    for (int i = 0; i < 6; i++) { // 6개의 led 제어
      if (i == count) // 카운트 된 박수 갯수로 led 제어
        digitalWrite(led[i], HIGH);
      else
        digitalWrite(led[i], LOW);
    }
    count = (count < 6) ? count + 1 : 0; // count < 6가 참일 때 count + 1, 거짓일때 0 반환
    delay(200); // 박수 중복 입력이 안되게 200ms 딜레이
  }
  else // 감지된 소리의 크기가 500 이하일 때
    delay(1);
}
