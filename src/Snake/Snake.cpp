#include "Snake.h"
#include "../Matrix/Matrix.h"

void Snake::begin() {

  longitud = 2;

  snakeX[0] = 1;
  snakeY[0] = 1;

  snakeX[1] = 0;
  snakeY[1] = 1;

  direccionX = 1;
  direccionY = 0;

  generarComida();
}

void Snake::update() {

  if(millis()-ultimoMovimiento > 400) {

    mover();

    dibujar();

    ultimoMovimiento = millis();
  }
}

void Snake::mover() {

  for(int i=longitud;i>0;i--) {

    snakeX[i] = snakeX[i-1];
    snakeY[i] = snakeY[i-1];
  }

  snakeX[0] += direccionX;
  snakeY[0] += direccionY;

  if(snakeX[0] > 3) snakeX[0] = 0;
  if(snakeX[0] < 0) snakeX[0] = 3;

  if(snakeY[0] > 3) snakeY[0] = 0;
  if(snakeY[0] < 0) snakeY[0] = 3;

  if(
    snakeX[0] == comidaX &&
    snakeY[0] == comidaY
  ) {

    longitud++;

    generarComida();
  }
}

void Snake::dibujar() {

  Matrix::clear();

  for(int i=0;i<longitud;i++) {

    Matrix::setLed(
      snakeX[i],
      snakeY[i],
      0,
      255,
      0
    );
  }

  Matrix::setLed(
    comidaX,
    comidaY,
    255,
    0,
    0
  );

  Matrix::update();
}

void Snake::generarComida() {

  comidaX = random(0,4);
  comidaY = random(0,4);
}