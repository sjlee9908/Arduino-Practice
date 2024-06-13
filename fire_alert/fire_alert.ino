int led =13;
int buzzer =6;
int fire=A0;
int state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(fire,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  state=analogRead(fire);
  digitalWrite(led,LOW);
  noTone(buzzer);

  if (state == 0){
    Serial.println("OFF:0");
    digitalWrite(led,LOW);
    noTone(buzzer);    
    }

    else{
      Serial.println("ON:"+(String)state);
      digitalWrite(led,HIGH);
      tone(buzzer, 500,100);
      }
delay(100);
}
