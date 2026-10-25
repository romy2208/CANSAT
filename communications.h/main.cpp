#include <Arduino.h>
#include "communications.h"
#include "sensors.h"
#include "states.h"
#include "actuators.h"

#define SERIAL_BAUD 115200

void setup() {
  Serial.begin(SERIAL_BAUD);
  delay(1000);

  // Mandar a llamar funciones 
  inicializarComunicaciones();
  inicializarSensores();
  inicializarMaquinaEstados();
  inicializarActuadores();
}

void loop() {
  // Realizamos las tareaaas 
  gestionarComunicaciones();
  leerSensores();
  actualizarMaquinaEstados();
}