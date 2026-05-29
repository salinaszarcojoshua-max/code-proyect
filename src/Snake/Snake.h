#ifndef Snake_h
#define Snake_h

#include <Arduino.h>

class Snake {

public:

  void begin();

  void update();

private:

  int snakeX[64];
  int snakeY[64];

  int longitud;

  int direccionX;
  int direccionY;

  int comidaX;
  int comidaY;

  unsigned long ultimoMovimiento;

  void mover();

  void dibujar();

  void generarComida();

  bool colision();
};

#endif