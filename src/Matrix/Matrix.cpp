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
  15,14,13,12,11,10,9,8,
  16,17,18,19,20,21,22,23,
  31,30,29,28,27,26,25,24,
  32,33,34,35,36,37,38,39,
  47,46,45,44,43,42,41,40,
  48,49,50,51,52,53,54,55,
  63,62,61,60,59,58,57,56

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