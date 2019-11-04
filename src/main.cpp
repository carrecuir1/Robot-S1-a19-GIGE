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
  SERVO_Disable(0);
  if(ROBUS_IsBumper(3))
  {
     //suiveurLigne follow;
     //follow.suivreLigneDroite();
    Serial.println(analogRead(0)*5.0/1023.0);
    Serial.println(analogRead(1)*5.0/1023.0);
    Serial.println(analogRead(2)*5.0/1023.0);
    Serial.println("---");
    delay(50);
  }
}
