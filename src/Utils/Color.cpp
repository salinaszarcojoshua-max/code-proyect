#include "Color.h"

uint8_t Color::ultimoR = 0;
uint8_t Color::ultimoG = 0;
uint8_t Color::ultimoB = 0;

uint32_t Color::rgb(
  uint8_t r,
  uint8_t g,
  uint8_t b
) {

  ultimoR = r;
  ultimoG = g;
  ultimoB = b;

  return (
    ((uint32_t)r << 16) |
    ((uint32_t)g << 8) |
    b
  );
}