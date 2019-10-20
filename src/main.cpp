#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/PID.h>
#include <Structure/Motor.h>

#define consigne 0.35
bool test;
void setup() {
  BoardInit();
  test = true;
}

void loop() {
    float voltage0, voltage1, voltage2;
    int sensorValue0, sensorValue1, sensorValue2;
  if(ROBUS_IsBumper(3)){
    Serial.begin(9600);
    sensorValue0 = analogRead(0);
    sensorValue1 = analogRead(1);
    sensorValue2 = analogRead(2);
    voltage0 = sensorValue0 * 5.0/1023.0;
    voltage1 = sensorValue1 * 5.0/1023.0;
    voltage2 = sensorValue2 * 5.0/1023.0;
    Serial.println(voltage0);
    Serial.println(voltage1);
    Serial.println(voltage2);
}
