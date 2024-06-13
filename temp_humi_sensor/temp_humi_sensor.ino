//DHT센서에서 받은 값을 표시//

#include <SimpleDHT.h>
#include <DHT11.h>


int pin=2;   
DHT11 dht11(pin); 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int err;
  float temp, humi;
  if((err=dht11.read(humi,temp))==0)
  {
    Serial.println();
    Serial.print("temp:"+(String)temp+"*C");
    Serial.println();
    Serial.print("humi:"+(String)humi+"%");
    delay(1500);
    }
      else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY);
}
