//조도센서를 이용함//

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ar=analogRead(A0);
  if(ar>900)
      digitalWrite(13,1);
   else if(ar<800)
       digitalWrite(13,0);
   Serial.println("anallog value:" +(String)ar);
   delay(10);

}
