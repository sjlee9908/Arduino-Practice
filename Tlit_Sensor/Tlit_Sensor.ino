int SW;
int red = 6;
int blu = 7;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blu,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  SW=analogRead(A1);

  if(SW >= 50){
    digitalWrite(red,HIGH);
    digitalWrite(blu,LOW);
    Serial.println(SW);
    delay(300);
    }
    else{
      digitalWrite(blu,HIGH);
      digitalWrite(red,LOW);
      Serial.println(SW);
      delay(300);
      
      
      }

}
