#include <Stepper.h>

// 모터별 스탭 수 설정 (28YBJ-48의 경우 64)
const int stepsPerRevolution = 64;
Stepper stepper(stepsPerRevolution, 8, 10, 9, 11);


void setup() {
  stepper.setSpeed(220); // 속도 설정
}


void loop() {
  int sensorReading = analogRead(A0); // 조이스틱 X축 A0에 연결

  if (sensorReading < 300) {
    stepper.step(1); // 좌 회전
  }
  if (sensorReading > 800) {
    stepper.step(-1); // 우 회전
  }
}
