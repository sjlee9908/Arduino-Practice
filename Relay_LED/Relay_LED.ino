int Relaypin=12;
int Switch=9;


void setup() {
  // put your setup code here, to run once:
  pinMode(Relaypin,OUTPUT);
  pinMode(Switch,INPUT_PULLUP);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(Switch)==LOW)
  {
    digitalWrite(Relaypin,HIGH);
    delay(100);
    }
    else
    {
      digitalWrite(Relaypin,LOW);
      delay(100);
      }
}
