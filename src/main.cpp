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

 if(ROBUS_IsBumper(3)){
    float voltage0, voltage1, voltage2;
    Serial.begin(9600);
    int sensorValue0 = analogRead(0), sensorValue1 = analogRead(1), sensorValue2 = analogRead(2);
    voltage0 = sensorValue0 * 5.0/1023.0;
    voltage1 = sensorValue1 * 5.0/1023.0;
    voltage2 = sensorValue2 * 5.0/1023.0;
    Serial.println("Voltage 1 : " + voltage0);
    Serial.println("Voltage 2 : " + voltage1);
    Serial.println("Voltage 3 : " + voltage2);
  }
}
