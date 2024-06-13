int a = 9; // 7세그먼트 핀 번호
int b = 13;
int c = 5;
int d = 3;
int e = 2;
int f = 10;
int g = 6;
int DP = 4; // dot is not used in this project
int D1 = 8;
int D2 = 11;
int D3 = 12;
int D4 = 7;

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
  pinMode(DP, OUTPUT);
}

void loop() {
  int a = analogRead(potentiometer); // a에 가변 저항 값 받기

  int space1 = a / 1000; // 첫 번째 자리 천의 자리
  int space2 = (a % 1000) / 100; // 두 번째 자리 백의 자리
  int space3 = (a % 100) / 10; // 세 번째 자리 십의 자리
  int space4 = a % 10; // 네 번째 자리 일의 자리

  digitalWrite(D4, HIGH); // 4번째 자리 출력
  selectnum(space4);
  delay(delayTime);
  digitalWrite(D4, LOW);

  digitalWrite(D3, HIGH); // 3번째 자리 출력
  selectnum(space3);
  delay(delayTime);
  digitalWrite(D3, LOW);

  digitalWrite(D2, HIGH); // 2번째 자리 출력
  selectnum(space2);
  delay(delayTime);
  digitalWrite(D2, LOW);

  digitalWrite(D1, HIGH); // 1번째 자리 출력
  selectnum(space1);
  delay(delayTime);
  digitalWrite(D1, LOW);
}

void selectnum(int x) { // 0~9까지의 숫자 중 무엇을 출력할지 결정
  switch (x) {
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
