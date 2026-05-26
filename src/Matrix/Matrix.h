#ifndef Matrix_h
#define Matrix_h

#include "Arduino.h"

class Matrix {

  public:

    static void begin();

    static void clear();

    static void update();

    static void setLed(
      uint8_t x,
      uint8_t y,
      uint8_t r,
      uint8_t g,
      uint8_t b
    );

  private:

    static uint8_t brillo;

    static uint8_t ancho;

    static uint8_t alto;
};

#endif