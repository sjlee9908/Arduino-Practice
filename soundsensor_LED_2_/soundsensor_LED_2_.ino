//소리에 따라 켜지는 led//
  
  
  int soundsensor=A0;
  int led[6]={8,9,10,11,12,13};
  int threshold=500;
  int count=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(soundsensor,INPUT);
  for (int i=0; i<6; i++)
    pinMode(led[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for (analogRead(soundsensor)>0)
  if(500>analogRead(soundsensor)>=400){
        digitalWrite(13,1);
        digitalWrite(12,0);
        digitalWrite(11,0);
        digitalWrite(10,0);
        digitalWrite(9,0);
        digitalWrite(8,0);}



  if(600>analogRead(soundsensor)>=500){
        digitalWrite(13,1);
        digitalWrite(12,1);
        digitalWrite(11,0);
        digitalWrite(10,0);
        digitalWrite(9,0);
        digitalWrite(8,0);}

  
  if(700>analogRead(soundsensor)>=600){
        digitalWrite(13,1);
        digitalWrite(12,1);
        digitalWrite(11,1);
        digitalWrite(10,0);
        digitalWrite(9,0);
        digitalWrite(8,0);}

  if(800>analogRead(soundsensor)>=700){
        digitalWrite(13,1);
        digitalWrite(12,1);
        digitalWrite(11,1);
        digitalWrite(10,1);
        digitalWrite(9,0);
        digitalWrite(8,0);}

  if(900>analogRead(soundsensor)>=800){
        digitalWrite(13,1);
        digitalWrite(12,1);
        digitalWrite(11,1);
        digitalWrite(10,1);
        digitalWrite(9,1);
        digitalWrite(8,0);}

  if(1000>analogRead(soundsensor)>=900){
        digitalWrite(13,1);
        digitalWrite(12,1);
        digitalWrite(11,1);
        digitalWrite(10,1);
        digitalWrite(9,1);
        digitalWrite(8,1);}
    
    
    Serial.println();
    Serial.print(analogRead(soundsensor));
    

}
