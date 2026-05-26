#include <NeoPixelEffects.h>

void setup() {

  DAC::begin();
}

void loop() {

  uint16_t x =
  ((sin(millis()/1000.0)+1.0)/2.0)
  * 4095;

  DAC::enviar(x);

  delay(50);
}