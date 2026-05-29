#ifndef Effects_h
#define Effects_h

#include "Arduino.h"

class Effects {

  public:

    static void ondas(float t);

    static void arcoiris(float t);

    static void circular(float t);

    static void randomRGB();

  private:

    static constexpr size_t N = 8;
};

#endif