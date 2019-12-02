#include <Main.h>
int state = 0;

void setup() 
{
 BoardInit();
 Serial.begin(38400);
}

void loop()
{ 
  int state;
  if(Serial.available()){
    state = Serial.read();
  }

  if(state == '0'){
    MOTOR_SetSpeed(0,0.1);
    MOTOR_SetSpeed(1,0);
    state = 0;
  }

  if(state == '1'){

    MOTOR_SetSpeed(1,0.1);
    MOTOR_SetSpeed(0,0);
    state = 0;
  }
}