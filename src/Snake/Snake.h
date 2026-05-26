#ifndef Snake_h
#define Snake_h

#include "Arduino.h"

class Snake {

  public:

    void begin();

    void update();

  private:

    int snakeX[16];
    int snakeY[16];

    int longitud;

    int comidaX;
    int comidaY;

    int direccionX;
    int direccionY;

    unsigned long ultimoMovimiento;

    void mover();

    void dibujar();

    void generarComida();
};

#endif