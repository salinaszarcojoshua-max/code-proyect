#include <NeoPixelEffects.h>

Snake juego;

void setup() {

  Matrix::begin();

  juego.begin();
}

void loop() {

  juego.update();
}