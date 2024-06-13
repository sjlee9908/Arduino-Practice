//3개의 버튼으로 RGB 조도 조절//

int redpin=6;
int greenpin=5;
int bluepin=3;

int redbutton=10;
int greenbutton=9;
int bluebutton=8;

int red=0;
int green=0;
int blue=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(bluepin,OUTPUT);

  pinMode(redbutton,INPUT_PULLUP);
  pinMode(greenbutton,INPUT_PULLUP);
  pinMode(bluebutton,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(redbutton)==0){
    if(red>225)
     red=0;
    red=red+30;
    delay(200);
    }
  if (digitalRead(greenbutton)==0){
    if(green>225)
     green=0;
    green=green+30;
    delay(200);
    }
  if (digitalRead(bluebutton)==0){
    if(blue>225)
     blue=0;
    blue=blue+30;
    delay(200);
    }
    {
    Serial.println();
    Serial.println();
    Serial.print("red:"+(String)red);
    Serial.println();
    Serial.print("green:"+(String)green);
    Serial.println();
    Serial.print("blue:"+(String)blue);
    Serial.print("");
    delay(1000);
    }
light(red, green, blue);
}

void light(int red, int green, int blue)
{ analogWrite(redpin,red);
analogWrite(greenpin,green);
analogWrite(bluepin,blue); 
  }
