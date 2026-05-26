#ifndef Color_h
#define Color_h

#include "Arduino.h"

class Color {

  public:

    static uint32_t rgb(
      uint8_t r,
      uint8_t g,
      uint8_t b
    );

  private:

    static uint8_t ultimoR;

    static uint8_t ultimoG;

    static uint8_t ultimoB;
};

#endif