#include "DAC.h"
#include <Wire.h>

const uint8_t DAC::Addr0 =
0b01100000;

uint8_t DAC::Msg1 =
0b0000;

void DAC::begin() {

  Wire.begin();
}

void DAC::enviar(uint16_t x) {

  Wire.beginTransmission(Addr0);

  Wire.write(
    Msg1 |
    ((x>>8)&0xF)
  );

  Wire.write(
    x & 0xFF
  );

  Wire.endTransmission();
}