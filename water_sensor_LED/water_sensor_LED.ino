int waterpin=A5;
int red=2;
int green=3;
int blue=4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(waterpin,INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int height= analogRead(A5);
  Serial.println(analogRead(A5));
  
  
  if (height<=300) {
    digitalWrite(red,0);
    digitalWrite(green,0);
    digitalWrite(blue,0);
  }

  else if(300<height && height<=400){
    digitalWrite(red,1);
    digitalWrite(green,0);
    digitalWrite(blue,0);
  }

  else if(400<height && height<=500){
    digitalWrite(red,1);
    digitalWrite(green,1);
    digitalWrite(blue,0);
  }
  
  else {
    digitalWrite(red,1);
    digitalWrite(green,1);
    digitalWrite(blue,1);
  }
  delay(100);
}
