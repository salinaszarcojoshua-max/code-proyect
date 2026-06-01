#include <NeoPixelEffects.h>

Snake juego;

void setup() {

  Matrix::begin();

  randomSeed(analogRead(A0));

  juego.begin();
}

void loop() {

  juego.update();
}