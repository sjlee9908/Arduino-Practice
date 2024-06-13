int leds[] = {2, 3, 4, 5, 6, 7, 8, 9}; // 지정된 7세그먼트 led 개수
int led_num = 8; // 7세그먼트 led
int button = 13; // 택트 스위치의 핀 번호
int num = 0; // 현재 LED에 표시되고 있는 숫자

// 캐소드 7 세그먼트의 숫자 및 LED값 정의
int set_number[10][8] = { // 각 숫자에 대한 LED 설정 값을 정의
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0 캐소드 7 세그먼트이므로 1이 HIGH, 0이 LOW
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0} // 9
};
void setup() {
  for (int i = 0; i < led_num; i++) { // 7세그먼트 led에 연결된 핀을 출력으로 설정
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button, INPUT_PULLUP); // 택트 스위치를 input_pullup으로 설정
}

void loop() {
  if (digitalRead(button) == LOW) { // 버튼이 한 번 눌릴때마다 7세그먼트 숫자가 하나씩 올라감
    if (num == 9)
      num = 0; // 7세그먼트에 표시됨
    else
      num ++;
  }
  for (int j = 0; j < led_num; j++) { // 7세그먼트 LED 출력
    digitalWrite(leds[j], set_number[num][j]);
  }
  delay(150);
}
