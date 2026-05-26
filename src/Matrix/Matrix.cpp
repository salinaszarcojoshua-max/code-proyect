#include "Matrix.h"
#include "NeoPixelDriver.h"

uint8_t Matrix::brillo = 255;

uint8_t Matrix::ancho = 4;

uint8_t Matrix::alto = 4;

void Matrix::begin() {

  NeoPixel::init();

  uint8_t Map[] = {
    15,14,13,12,
    8,9,10,11,
    7,6,5,4,
    0,1,2,3
  };

  NeoPixel::SetMapping(Map,16);
}

void Matrix::clear() {

  NeoPixel::Clear();
}

void Matrix::update() {

  NeoPixel::Update();
}

void Matrix::setLed(
  uint8_t x,
  uint8_t y,
  uint8_t r,
  uint8_t g,
  uint8_t b
) {

  NeoPixel::SetLed(
    x,
    y,
    (r * brillo)/255,
    (g * brillo)/255,
    (b * brillo)/255
  );
}