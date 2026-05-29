#include "Matrix.h"
#include "../Core/Config.h"

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel tira(
  TOTAL_LEDS,
  DATA_PIN,
  NEO_GRB + NEO_KHZ800
);

uint8_t Matrix::brillo = 255;

uint8_t Matrix::ancho = MATRIX_WIDTH;

uint8_t Matrix::alto = MATRIX_HEIGHT;

uint8_t Map[] = {

   0, 15, 16, 31, 32, 47, 48, 63,
   1, 14, 17, 30, 33, 46, 49, 62,
   2, 13, 18, 29, 34, 45, 50, 61,
   3, 12, 19, 28, 35, 44, 51, 60,
   4, 11, 20, 27, 36, 43, 52, 59,
   5, 10, 21, 26, 37, 42, 53, 58,
   6,  9, 22, 25, 38, 41, 54, 57,
   7,  8, 23, 24, 39, 40, 55, 56

};

void Matrix::begin() {

  tira.begin();

  tira.clear();

  tira.show();
}

void Matrix::clear() {

  tira.clear();
}

void Matrix::update() {

  tira.show();
}

void Matrix::setLed(
  uint8_t x,
  uint8_t y,
  uint8_t r,
  uint8_t g,
  uint8_t b
) {

  uint8_t index =
  Map[
    (y * MATRIX_WIDTH) + x
  ];

  tira.setPixelColor(
    index,
    tira.Color(
      (r * brillo)/255,
      (g * brillo)/255,
      (b * brillo)/255
    )
  );
}