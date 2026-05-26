#include "Effects.h"
#include "../Matrix/Matrix.h"

#define _USE_MATH_DEFINES
#include <math.h>

void Effects::ondas(float t) {

  for(size_t i=0;i<N;i++) {

    for(size_t j=0;j<N;j++) {

      float thetaA =
      (TWO_PI * j) /
      static_cast<float>(N);

      float thetaB =
      (TWO_PI * i) /
      static_cast<float>(N);

      float A =
      (sin(thetaA+t)+1)/2.0;

      float B =
      (sin(thetaB+t)+1)/2.0;

      Matrix::setLed(
        i,
        j,
        A*255,
        B*255,
        (sin(thetaA)+1)/2 *255
      );
    }
  }

  Matrix::update();
}

void Effects::arcoiris(float t) {

  for(size_t i=0;i<N;i++) {

    for(size_t j=0;j<N;j++) {

      float angulo =
      t * 3 +
      (i * 0.8) +
      (j * 0.8);

      uint8_t r =
      (sin(angulo)+1)*127;

      uint8_t g =
      (sin(angulo+2)+1)*127;

      uint8_t b =
      (sin(angulo+4)+1)*127;

      Matrix::setLed(
        i,
        j,
        r,
        g,
        b
      );
    }
  }

  Matrix::update();
}

void Effects::circular(float t) {

  for(size_t i=0;i<N;i++) {

    for(size_t j=0;j<N;j++) {

      float distancia =
      sqrt(
        pow(i - 1.5,2) +
        pow(j - 1.5,2)
      );

      float brillo =
      (sin((distancia*4)-(t*5))+1)*127;

      Matrix::setLed(
        i,
        j,
        brillo,
        0,
        255-brillo
      );
    }
  }

  Matrix::update();
}

void Effects::randomRGB() {

  for(size_t i=0;i<N;i++) {

    for(size_t j=0;j<N;j++) {

      Matrix::setLed(
        i,
        j,
        random(0,256),
        random(0,256),
        random(0,256)
      );
    }
  }

  Matrix::update();

  delay(150);
}