//밝아졌다가 어두워짐//


void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i< 256;i++)
  {
        analogWrite(11,i);
        delay(10);
        Serial.println(i);
  }
  for(int i=256;i>0;i--)
  {
        analogWrite(11,i);
        delay(10);
        Serial.println(i);
  }
}
