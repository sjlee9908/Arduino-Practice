//가변저항을 7세그먼트로 표시, led로도 저항 표시//

int a = 9; // 7세그먼트 핀 번호
int b = 13;
int c = 5;
int d = 4;
int e = 2;
int f = 10;
int g = 6;
// dot is not used in this project
int D1 = 8;
int D2 = 11;
int D3 = 12;
int D4 = 7;
int LED= 3;

int space1, space2, space3, space4;
int potentiometer = A0; // 가변 저항 제어 핀

const int delayTime = 5; // delay set to 5 ms

void setup() {
  pinMode(a, OUTPUT); // 각각의 7세그먼트 핀들을 출력으로 설정
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(LED,OUTPUT);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  int a= analogRead(potentiometer);
  
  int a1= a / 4;

  int space1=a/1000;
  int space2=(a%1000)/100;
  int space3=(a%100)/10;
  int space4=a%10;

  analogWrite(LED,a1);

  digitalWrite(D4,1);
  selectnum(space4);
  delay(delayTime);
  digitalWrite(D4,0);
  
  digitalWrite(D3,1);
  selectnum(space3);
  delay(delayTime);
  digitalWrite(D3,0);
  
  digitalWrite(D2,1);
  selectnum(space2);
  delay(delayTime);
  digitalWrite(D2,0);
  
  digitalWrite(D1,1);
  selectnum(space1);
  delay(delayTime);
  digitalWrite(D1,0);
}

void selectnum(int x){
  switch(x){
    case 1: num1(); break;
    case 2: num2(); break;
    case 3: num3(); break;
    case 4: num4(); break;
    case 5: num5(); break;
    case 6: num6(); break;
    case 7: num7(); break;
    case 8: num8(); break;
    case 9: num9(); break;
    default: num0(); break;
    }
  }

void num1() { // 1출력
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
}

void num2() { // 2출력
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
}

void num3() { // 3출력
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
}

void num4() { // 4출력
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}

void num5() { // 5출력
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}

void num6() { // 6출력
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}

void num7() { // 7출력
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
}

void num8() { // 8출력
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}

void num9() { // 9출력
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}

void num0() { // 0출력
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 1);
}
