#include <NeoPixelEffects.h>

void setup() {

  Matrix::begin();
}

void loop() {

  Matrix::clear();

  Matrix::setLed(
    0,
    0,
    255,
    0,
    0
  );

  Matrix::setLed(
    1,
    1,
    0,
    255,
    0
  );

  Matrix::setLed(
    2,
    2,
    0,
    0,
    255
  );

  Matrix::setLed(
    3,
    3,
    255,
    255,
    255
  );

  Matrix::update();

  delay(500);
}