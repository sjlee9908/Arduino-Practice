
#include <IRremote.h>
int RECV_PIN= A0;
int LED= 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LED,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    switch (results.value){
      case 0xC101E57B: digitalWrite(LED,LOW); // LED Off
      break;
      case 0x9716BE3F: digitalWrite(LED,HIGH); // LED On
      break;
      }
    irrecv.resume();
    }

}
