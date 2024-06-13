//버튼을 누르면 신호등이 켜짐//

void setup() {
  // put your setup code here, to run once:
  
  pinMode(13 ,OUTPUT);
  pinMode(12 ,OUTPUT);
  pinMode(11 ,OUTPUT);
  pinMode(10 ,OUTPUT);
  pinMode(9 ,OUTPUT);
  pinMode(8 ,INPUT_PULLUP);

}
 
void loop() {
  // put your main code here, to run repeatedly:
  int sw=digitalRead(8);
   
  if(sw==0)
  {
  digitalWrite(11,1);
  delay(1000);
  digitalWrite(11,0);
  digitalWrite(12,1);
  delay(1000);
  digitalWrite(12,0);
  digitalWrite(13,1);
  digitalWrite(9,1);
  delay(5000);
  digitalWrite(9,0);
  delay(2000);
  digitalWrite(9,1);
  delay(2000);
  digitalWrite(9,0);
  delay(2000);
  digitalWrite(9,1);
  delay(2000);   
  }
  
  else
  {
  digitalWrite(13,0);
  digitalWrite(12,0);
  digitalWrite(11,1);
  digitalWrite(10,0);
  digitalWrite(9,0);
  }   
}
