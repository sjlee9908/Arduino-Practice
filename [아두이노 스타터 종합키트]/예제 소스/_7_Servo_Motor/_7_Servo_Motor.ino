#include <Servo.h>
Servo EduServo;
int pos = 0; // 서보 모터의 각도 조절 변수

void setup() {
  EduServo.attach(4); // 디지털 핀 4번에 연결
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // 0 ~ 180도 회전
    EduServo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // 180 ~ 0도 회전
    EduServo.write(pos);
    delay(15);
  }
}
