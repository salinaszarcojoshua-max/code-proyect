#include <NeoPixelEffects.h>

Snake juego;

uint8_t modo = 0;

unsigned long cambioModo = 0;

void setup() {

  Matrix::begin();

  juego.begin();
}

void loop() {

  float t =
  millis()/1000.0;

  if(millis() - cambioModo > 10000) {

    modo++;

    if(modo > 4) {

      modo = 0;
    }

    cambioModo = millis();
  }

  switch(modo) {

    case 0:

      Effects::ondas(t);

    break;

    case 1:

      Effects::arcoiris(t);

    break;

    case 2:

      Effects::circular(t);

    break;

    case 3:

      Effects::randomRGB();

    break;

    case 4:

      juego.update();

    break;
  }
}