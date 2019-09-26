#include <Arduino.h>
#include <../lib/LibRobUS/src/LibRobus.h>
float speed_G;
float speed_D;

void setup() {
  BoardInit();
  speed_G = 0.5;
  speed_D = 0.5;
  
}

void loop() {
  int encoder_G, encoder_D;
  if(ROBUS_IsBumper(3)){
    while(!ROBUS_IsBumper(2) and !ROBUS_IsBumper(1) and !ROBUS_IsBumper(0)){
        encoder_G = ENCODER_ReadReset(0);
        encoder_D = ENCODER_ReadReset(1);
        MOTOR_SetSpeed(1, speed_G);
        MOTOR_SetSpeed(0, speed_D);
        speed_G = speed_G + 0.00015*(encoder_D - encoder_G);
        delay(100);
      }

  }
  MOTOR_SetSpeed(1, 0);
  MOTOR_SetSpeed(0, 0);
}

