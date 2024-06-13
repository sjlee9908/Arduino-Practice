#include <Servo.h>

Servo servo; // 서보모터를 'servo' 로 정의
int angle = 90; // angle(각도) 정수변수 정의
int Servo_pin = 7; //변수 Servo_pin을 7로 선언
int Joystick_pin = A0; // 변수 Joystick_pin을 A0로 선언
void setup() {
  
  servo.attach(Servo_pin); // servo 7번에 연결
  servo.write(angle); // servo 를 중간 점으로 지정 (중간 = 90)
}

void loop() {

  int value; // 조이스틱의 아날로그 값
  value = analogRead(Joystick_pin); // A0에서 읽어온 값을 value로 선언

  if (value < 400) // 조이스틱 X축 값이 400 이하 일 때
  {
    if (angle < 180) // angle(각도)이 180보다 작을 때
    {
      servo.write(angle++); // angle 증가
      delay(10); //속도 조절용 딜레이
    }
    else if (angle == 180)
    {} // angle 변수값이 180도가 되었을 때, 대기
  }

  else if (value > 800) //조이스틱 X축 값이 800 이상 일 때
  {
    if (angle > 0) //각도가 0보다 크면
    {
      servo.write(angle--); //angle 감소
      delay(10); //속도 조절용 딜레이
    }
    else if (angle = 0)
    {} // angle 변수값이 0도가 되었을 때 대기
  }
}

