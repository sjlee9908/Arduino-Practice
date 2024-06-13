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
  if(analogRead(soundsensor)>=threshold){
    for (int i=0; i<6; i++){
      if(i==count)
        digitalWrite(led[i],1);
      else
        digitalWrite(led[i],0);
      }
    count=(count<6) ? count+1:0;
    delay(200);
    }
    else
    delay(1);
    
    
    Serial.println();
    Serial.print(analogRead(soundsensor));
    

}
