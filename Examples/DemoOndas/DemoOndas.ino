#include <NeoPixelEffects.h>

void setup() {

  Matrix::begin();
}

void loop() {

  float t =
  millis()/1000.0;

  Effects::ondas(t);
}