# NeoPixelEffects

Libreria modular para matrices NeoPixel RGB 8x8 desarrollada mediante Programación Orientada a Objetos para Arduino.

Incluye:

- Control de matriz RGB
- Efectos visuales
- Juego Snake
- Comunicación DAC por I2C
- Utilidades RGB
- Arquitectura modular reutilizable

## Caracteristicas

- Arquitectura modular
- Efectos RGB
- Juego Snake
- DAC por I2C
- Control de matriz
- Utilidades RGB
- Compatible con Arduino Uno, Nano y plataformas compatibles

---

# Estructura

NeoPixelEffects/
│
├── src/
├── examples/
├── library.properties
├── keywords.txt
└── README.md

---

# Modulos

## Matrix

Control de la matriz NeoPixel.

Funciones:

- begin()
- clear()
- update()
- setLed()

---

## Effects

Animaciones RGB.

Funciones:

- ondas()
- arcoiris()
- circular()
- randomRGB()

---

## Snake

Juego Snake para matriz 8x8 con control mediante botones físicos.

Funciones:

- begin()
- update()

---

## DAC

Control DAC por I2C.

Funciones:

- begin()
- enviar()

---

## Color

Utilidades RGB.

Funciones:

- rgb()

---

# Instalacion

Copiar la carpeta:

NeoPixelEffects

en:

Documentos/Arduino/libraries/

Luego reiniciar Arduino IDE.

---

# Uso Basico

```cpp
#include <NeoPixelEffects.h>

Snake juego;

void setup() {

  Matrix::begin();

  juego.begin();
}

void loop() {

  juego.update();
}