#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/suiveurLigne.h>

#define consigne 0.35
bool test;
void setup() {
  BoardInit();
  Serial.begin(9600);
}

void loop() {
      suiveurLigne follow;
      follow.suivreLigneDroite();
}
