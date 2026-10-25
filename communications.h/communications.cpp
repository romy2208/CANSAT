#include "communications.h"

HardwareSerial XBee(2);
#define XBEE_RX 16
#define XBEE_TX 17
#define XBEE_BAUD 9600

const char* NOMBRE_LOCAL = "CANSAT";
const char* NOMBRE_REMOTO = "ESTACION";
const char* PAN_ID = "No.registro";
const char* SH_DESTINO = "12A200";
const char* SL_DESTINO = "13A200";

const char* MENSAJE = "arriba los pumas";
const unsigned long INTERVALO = 1000;
unsigned long tiempoAnterior = 0;
uint32_t contador = 0;
bool xbeeConfigurado = false;

String comandoAT(String comando) {
  while (XBee.available()) {
    XBee.read();
  }
  XBee.print("AT");
  XBee.print(comando);
  XBee.write('\r');

  String respuesta = XBee.readStringUntil('\r');
  respuesta.trim();
  return respuesta;
}

bool iniciarModoAT() {
  while (XBee.available()) {
    XBee.read();
  }
  delay(1200);
  XBee.print("+++");
  XBee.flush();
  delay(1200);

  String respuesta = XBee.readStringUntil('\r');
  respuesta.trim();
  return respuesta == "OK";
}

bool configurarXBee() {
  if (!iniciarModoAT()) return false;
  comandoAT("SH");
  comandoAT("SL");

  bool ok = true;
  if (comandoAT(String("NI") + NOMBRE_LOCAL) != "OK") ok = false;
  if (comandoAT(String("ID") + PAN_ID) != "OK") ok = false;
  if (comandoAT(String("DH") + SH_DESTINO) != "OK") ok = false;
  if (comandoAT(String("DL") + SL_DESTINO) != "OK") ok = false;
  if (comandoAT("AP0") != "OK") ok = false;

  if (ok) {
    if (comandoAT("WR") != "OK") ok = false;
  }
  comandoAT("CN");
  return ok;
}

void inicializarComunicaciones() {
  XBee.begin(XBEE_BAUD, SERIAL_8N1, XBEE_RX, XBEE_TX);
  XBee.setTimeout(1500);
  xbeeConfigurado = configurarXBee();
}

void gestionarComunicaciones() {
  if (!xbeeConfigurado) return;

  if (millis() - tiempoAnterior >= INTERVALO) {
    tiempoAnterior = millis();
    contador++;
    XBee.println(MENSAJE);
  }

  while (XBee.available()) {
    char dato = XBee.read();
    Serial.write(dato);
  }
}