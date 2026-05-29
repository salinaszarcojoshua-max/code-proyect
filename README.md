# NeoPixelEffects

Libreria modular para matrices NeoPixel 4x4.

## Caracteristicas

- Arquitectura modular
- Efectos RGB
- Juego Snake
- DAC por I2C
- Control de matriz
- Utilidades RGB
- Compatible con Arduino y ESP32

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

Juego Snake para matriz 4x4.

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