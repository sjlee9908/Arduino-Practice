//조이스틱을 이용한 서보모터 제어//


#include <Servo.h>

Servo servo;
int angle = 90;
int Servo_pin=7;
int Joystick_pin=A0;


void setup() {
  // put your setup code here, to run once:
  servo.attach(Servo_pin);
  servo.write(angle);
  Serial.begin(9600);
  unsigned long prev_time = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  int  value;
  value=analogRead(Joystick_pin);
  unsigned long prev_time = 0;
  unsigned long current_time= millis();
    
  if (value<400)
  {
    if (angle<180)
    {
      servo.write(angle++);
      delay(10);
      }
      else if (angle==180)
      {}
  }
     else if (value>800)
        {
          if (angle>0)
          {
            servo.write(angle--);
            delay(10);
            }
            else if (angle=0)
            {} 
        }
  Serial.println("angle:"+(String)angle);
  Serial.println("value:"+(String)value);
  Serial.println();
 delay(10);

    }
