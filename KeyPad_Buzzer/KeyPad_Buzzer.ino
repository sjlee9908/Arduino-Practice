#include <Keypad.h>

int buzzer=13;
const byte Rows=4;
const byte Cols=4;

char keys[Rows][Cols]={
  {'a','b','c','d'},
  {'e','f','g','h'},
  {'i','j','k','l'},
  {'m','n','o','p'},
};

byte rowpins[Rows]={2,3,4,5};
byte colpins[Cols]={6,7,8,9};

Keypad keypad = Keypad(makeKeymap(keys),rowpins,colpins,Rows,Cols);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key=keypad.getKey();
if(key!=NO_KEY){
  Serial.println(key);
  
  if(key=='a'){
    tone(buzzer,262,100);
    }
  
  if(key=='b'){
    tone(buzzer,293,100);
    }
    
  if(key=='c'){
    tone(buzzer,329,100);
    }
    
  if(key=='d'){
    tone(buzzer,349,100);
    }
    
  if(key=='e'){
    tone(buzzer,392,100);
    }
    
  if(key=='f'){
    tone(buzzer,440,100);
    }
  if(key=='g'){
    tone(buzzer,493,100);
    }
    
  if(key=='h'){
    tone(buzzer,524,100);
    }
    
  if(key=='i'){
    tone(buzzer,587,100);
    }
    
  if(key=='j'){
    tone(buzzer,659,100);
    }
    
  if(key=='k'){
    tone(buzzer,698,100);
    }
    
  if(key=='l'){
    tone(buzzer,784,100);
    }
    
  if(key=='m'){
    tone(buzzer,880,100);
    }
    
  if(key=='n'){
    tone(buzzer,987,100);
    }
    
  if(key=='o'){
    tone(buzzer,1046,100);
    }
    
  if(key=='g'){
    tone(buzzer,1174,100);
    }
  }
}
