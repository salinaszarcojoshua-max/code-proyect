#include "Snake.h"

#include "../Matrix/Matrix.h"

#define BTN_UP 2
#define BTN_DOWN 3
#define BTN_LEFT 4
#define BTN_RIGHT 5

void Snake::begin() {

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);

  longitud = 3;

  snakeX[0] = 4;
  snakeY[0] = 4;

  snakeX[1] = 3;
  snakeY[1] = 4;

  snakeX[2] = 2;
  snakeY[2] = 4;

  direccionX = 1;
  direccionY = 0;

  generarComida();

  ultimoMovimiento = millis();
}

void Snake::update() {

  if(!digitalRead(BTN_UP) && direccionY != 1){

    direccionX = 0;
    direccionY = -1;
  }

  else if(!digitalRead(BTN_DOWN) && direccionY != -1){

    direccionX = 0;
    direccionY = 1;
  }

  else if(!digitalRead(BTN_LEFT) && direccionX != 1){

    direccionX = -1;
    direccionY = 0;
  }

  else if(!digitalRead(BTN_RIGHT) && direccionX != -1){

    direccionX = 1;
    direccionY = 0;
  }

  if(millis() - ultimoMovimiento > 250){

    mover();

    dibujar();

    ultimoMovimiento = millis();
  }
}

void Snake::mover() {

  for(int i = longitud; i > 0; i--){

    snakeX[i] = snakeX[i-1];
    snakeY[i] = snakeY[i-1];
  }

  snakeX[0] += direccionX;
  snakeY[0] += direccionY;

  if(snakeX[0] > 7) snakeX[0] = 0;
  if(snakeX[0] < 0) snakeX[0] = 7;

  if(snakeY[0] > 7) snakeY[0] = 0;
  if(snakeY[0] < 0) snakeY[0] = 7;

  if(colision()){

    Matrix::clear();
    Matrix::update();

    delay(1000);

    begin();

    return;
  }

  if(
    snakeX[0] == comidaX &&
    snakeY[0] == comidaY
  ){

    if(longitud < 63){
      longitud++;
    }

    generarComida();
  }
}

void Snake::dibujar() {

  Matrix::clear();

  for(int i = 0; i < longitud; i++) {

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

bool Snake::colision() {

  for(int i = 1; i < longitud; i++){

    if(
      snakeX[0] == snakeX[i] &&
      snakeY[0] == snakeY[i]
    ){

      return true;
    }
  }

  return false;
}

void Snake::generarComida() {

  comidaX = random(0,8);
  comidaY = random(0,8);
}

