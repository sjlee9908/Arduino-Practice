//LED 세기 입력//

void setup() {
  // put your setup code here, to run once:
    pinMode(11,OUTPUT);
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   if(Serial.available()) 
   {
      int ri=Serial.parseInt();
      Serial.println(ri);
      analogWrite(11,ri);
   }

}
