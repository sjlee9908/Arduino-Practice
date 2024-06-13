int red_pin = 6; // 3색 LED 모듈의 핀 넘버 설정
int green_pin = 5;
int blue_pin = 3;

int red_control = 10; // 택트 스위치의 핀 넘버 설정
int green_control = 9;
int blue_control = 8;

int red = 0; // led의 출력 정도
int green = 0;
int blue = 0;

void setup() {
  pinMode(red_pin, OUTPUT); // 3색 LED 모듈 핀들을 출력으로 설정
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);

  pinMode(red_control, INPUT_PULLUP); // 택트 스위치를 풀업으로 설정
  pinMode(green_control, INPUT_PULLUP);
  pinMode(blue_control, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(red_control) == LOW) {
    if (red > 255)
      red = 0; // red LED 출력이 255를 넘으면 변수 red를 0으로 초기화
    red = red + 30;
    delay(200);
  }
  else if (digitalRead(green_control) == LOW) {
    if (green > 255)
      green = 0;
    green = green + 30;
    delay(200);
  }
  else if (digitalRead(blue_control) == LOW) {
    if (blue > 255)
      blue = 0;
    blue = blue + 30;
    delay(200);
  }
  show_light(red, green, blue); // red, green, blue 값을 led에 출력
}

void show_light(int red, int green, int blue) {
  analogWrite(red_pin, red); // RGB LED red_pin 핀이 연결된 자리에 변수 red만큼의 출력
  analogWrite(green_pin, green);
  analogWrite(blue_pin, blue);
}

