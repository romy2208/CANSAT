#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#include <Arduino.h>

extern HardwareSerial XBee;

void inicializarComunicaciones();
void gestionarComunicaciones();

#endif