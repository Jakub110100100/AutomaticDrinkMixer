#include "CartController.h"
#include <Arduino.h>

CartController cartController{};

void setup() {
    Serial.begin(9600);
    cartController.setPins();
    cartController.allowMovement();
    cartController.calibrate();
}

void loop() {
    cartController.blockMovement();
}
