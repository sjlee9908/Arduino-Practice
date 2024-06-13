//릴레이 유지//

int Relaypin=12;
int Switch=9;
int val=0;
int state=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Relaypin,OUTPUT);
  pinMode(Switch,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(Switch);
 if (val==LOW)
  {
    state=1-state;
    }
  if (state==1)
    {
      digitalWrite(Relaypin,HIGH);
      delay(1000);
      }
 if (state!=1){
  digitalWrite(Relaypin,LOW);
  delay(1000);
  }
}
