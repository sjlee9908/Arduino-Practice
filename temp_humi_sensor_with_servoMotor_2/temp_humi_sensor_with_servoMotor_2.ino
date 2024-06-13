//서보모터로 DHT센서 값 표시//
  
#include <SimpleDHT.h>
#include <DHT11.h>
#include <Servo.h>

Servo servo;

int servoPin=3;
int pin=2;   

DHT11 dht11(pin); 




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(servoPin);
 
}

void loop() {
  // put your main code here, to run repeatedly:
    int err;
  float temp, humi;
  
  if((err=dht11.read(humi,temp))==0)
  {
    Serial.println();
    Serial.print("temp:"+(String)temp+"*C");
    Serial.println();
    Serial.print("humi:"+(String)humi+"%");
    delay(1500);

    if(40<(int)humi<=50)
    {
    servo.write(30);
    delay(750);
    servo.write(0);
    delay(750);
    }
if(50<(int)humi<=60)
  {
    servo.write(60);
    delay(750);
    servo.write(0);
    delay(750);
  }
if(60<(int)humi<=70)
  {
    servo.write(90);
    delay(750);
    servo.write(0);
    delay(750);
  }
if(70<(int)humi<=80)
  {
    servo.write(120);
    delay(750);
    servo.write(0);
    delay(750);
  }
if(80<(int)humi<=90)
  {
    servo.write(150);
    delay(750);
    servo.write(0);
    delay(750);
  }
if(90<(int)humi<=100)
  {
    servo.write(180);
    delay(750);
    servo.write(0);
    delay(750);
  }
  }
        else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }

if(40<humi<=50)
  {
    servo.write(30);
    delay(750);
    servo.write(0);
    delay(750);
    }
if(50<humi<=60)
  {
    servo.write(60);
    delay(750);
    servo.write(0);
    delay(750);
  }
if(60<humi<=70)
  {
    servo.write(90);
    delay(750);
    servo.write(0);
    delay(750);
  }
if(70<humi<=80)
  {
    servo.write(120);
    delay(750);
    servo.write(0);
    delay(750);
  }
if(80<humi<=90)
  {
    servo.write(150);
    delay(750);
    servo.write(0);
    delay(750);
  }
if(90<humi<=100)
  {
    servo.write(180);
    delay(750);
    servo.write(0);
    delay(750);
  }
}
