#ifndef DAC_h
#define DAC_h

#include "Arduino.h"

class DAC {

  public:

    static void begin();

    static void enviar(uint16_t valor);

  private:

    static const uint8_t Addr0;

    static uint8_t Msg1;
};

#endif