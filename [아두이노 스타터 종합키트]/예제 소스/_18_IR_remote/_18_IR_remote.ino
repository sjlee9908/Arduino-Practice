#include <IRremote.h>
int RECV_PIN = A0; // 변수 RECV_PIN을 아날로그 핀 0번으로 선언
int LED_RED = 12; // 변수 LED_RED를 12로 선언
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600); // 시리얼 통신 속도 9600으로 초기화
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_RED, OUTPUT); // 디지털 핀 12번을 출력으로 선언
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // 시리얼 모니터에 리모콘 버튼의 고유값 출력
    switch (results.value) { // 리모콘 버튼의 고유값에 따라
      case 0xFF6897: digitalWrite(LED_RED, HIGH); // 리모콘의 0버튼이 눌리면, LED_RED ON
        break;
      case 0xFF30CF: digitalWrite(LED_RED, LOW); // 리모콘의 1버튼이 눌리면, LED OFF
        break;
    }
    irrecv.resume(); // 다음 값을 받는다.
  }
}
