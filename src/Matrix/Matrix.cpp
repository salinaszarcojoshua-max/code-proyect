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

  0,1,2,3,4,5,6,7,
  8,9,10,11,12,13,14,15,
  16,17,18,19,20,21,22,23,
  24,25,26,27,28,29,30,31,
  32,33,34,35,36,37,38,39,
  40,41,42,43,44,45,46,47,
  48,49,50,51,52,53,54,55,
  56,57,58,59,60,61,62,63

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

  if(x >= MATRIX_WIDTH || y >= MATRIX_HEIGHT){
    return;
  }

  uint8_t index =
    Map[
      (y * MATRIX_WIDTH) + x
    ];

  tira.setPixelColor(
    index,
    tira.Color(
      (r * brillo) / 255,
      (g * brillo) / 255,
      (b * brillo) / 255
    )
  );
}