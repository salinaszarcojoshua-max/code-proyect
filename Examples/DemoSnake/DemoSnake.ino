#include <NeoPixelEffects.h>

Snake juego;

#define BTN_UP     2
#define BTN_DOWN   3
#define BTN_LEFT   4
#define BTN_RIGHT  5

void setup() {

  Matrix::begin();

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);

  randomSeed(analogRead(A0));

  juego.begin();
}

void loop() {

  if(digitalRead(BTN_UP) == LOW) {

    juego.setDirection(
      0,
      -1
    );
  }

  if(digitalRead(BTN_DOWN) == LOW) {

    juego.setDirection(
      0,
      1
    );
  }

  if(digitalRead(BTN_LEFT) == LOW) {

    juego.setDirection(
      -1,
      0
    );
  }

  if(digitalRead(BTN_RIGHT) == LOW) {

    juego.setDirection(
      1,
      0
    );
  }

  juego.update();
} 