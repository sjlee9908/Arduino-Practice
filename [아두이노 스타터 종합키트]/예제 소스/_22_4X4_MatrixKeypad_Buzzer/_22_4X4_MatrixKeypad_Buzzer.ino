#include <Keypad.h>

int buzzer = 12; // 변수 buzzer을 12로 선언

const byte ROWS = 4; // 4행
const byte COLS = 4; // 4열

char keys[ROWS][COLS] = { // 키패드의 4행 4열을 정의
  {'a', 'b', 'c', 'd'},
  {'e', 'f', 'g', 'h'},
  {'i', 'j', 'k', 'l'},
  {'m', 'n', 'o', 'p'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; // 행에서 키패드가 연결된 디지털 핀들을 정의
byte colPins[COLS] = {6, 7, 8, 9}; // 열에서 키패드가 연결된 디지털 핀들을 정의

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {

  Serial.begin (9600);
  pinMode(buzzer, OUTPUT); // 디지털 핀 12번을 출력으로 설정


}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    Serial.println(key);

    if (key == 'a') {
      tone(buzzer, 2093, 100);
    }
    if (key == 'b') {
      tone(buzzer, 2349, 100);
    }
    if (key == 'c') {
      tone(buzzer, 2637, 100);
    }
    if (key == 'd') {
      tone(buzzer, 2793, 100);
    }
    if (key == 'e') {
      tone(buzzer, 3136, 100);
    }
    if (key == 'f') {
      tone(buzzer, 3520, 100);
    }
    if (key == 'g') {
      tone(buzzer, 3951, 100);
    }
    if (key == 'h') {
      tone(buzzer, 4186, 100);
    }
    if (key == 'i') {
      tone(buzzer, 2093, 100);
    }
    if (key == 'j') {
      tone(buzzer, 2349, 100);
    }
    if (key == 'k') {
      tone(buzzer, 2637, 100);
    }
    if (key == 'l') {
      tone(buzzer, 2793, 100);
    }
    if (key == 'm') {
      tone(buzzer, 3136, 100);
    }
    if (key == 'n') {
      tone(buzzer, 3520, 100);
    }
    if (key == 'o') {
      tone(buzzer, 3951, 100);
    }
    if (key == 'p') {
      tone(buzzer, 4186, 100);
    }
  }
}

