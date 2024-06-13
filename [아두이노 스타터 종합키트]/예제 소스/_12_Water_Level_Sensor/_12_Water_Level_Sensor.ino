int water_pin = A5; // 변수 water_pin을 A5라 선언
int LED_red = 2; // 변수 LED_color를  2, 3, 4라 선언
int LED_green = 3;
int LED_blue = 4;

void setup() {
  Serial.begin(9600); // 시리얼 통신 속도 9600
  pinMode(water_pin, INPUT); // 아날로그 핀 A5을 입력으로 설정
  pinMode(LED_red, OUTPUT); // 디지털 핀 2, 3, 4를 출력으로 설정
  pinMode(LED_green, OUTPUT);
  pinMode(LED_blue, OUTPUT);
}

void loop() {
  Serial.println(analogRead(water_pin)); // water_pin의 값을 시리얼 모니터에 출력
  if (analogRead(water_pin) <= 50) { // water_pin이 50 이하면 모든 LED off
    digitalWrite(LED_red, LOW);
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_blue, LOW);
  }
  else if (50 < analogRead(water_pin) && analogRead(water_pin) <= 100) {
    digitalWrite(LED_red, HIGH); // 50<water_pin<=100이면 LED_red on
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_blue, LOW);
  }
  else if (100 < analogRead(water_pin) && analogRead(water_pin) <= 150) {
    digitalWrite(LED_red, HIGH);
    digitalWrite(LED_green, HIGH); // 100<water_pin<=150이면 LED_red, green on
    digitalWrite(LED_blue, LOW);
  }
  else {
    digitalWrite(LED_red, HIGH);
    digitalWrite(LED_green, HIGH);
    digitalWrite(LED_blue, HIGH); // 이외의 모든 경우 LED_red, green, blue on
  }
  delay(50);
}
