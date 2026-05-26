#include <NeoPixelEffects.h>

void setup() {

  Serial.begin(115200);
}

void loop() {

  uint32_t rojo =
  Color::rgb(
    255,
    0,
    0
  );

  uint32_t verde =
  Color::rgb(
    0,
    255,
    0
  );

  uint32_t azul =
  Color::rgb(
    0,
    0,
    255
  );

  Serial.println(rojo);

  Serial.println(verde);

  Serial.println(azul);

  delay(1000);
}