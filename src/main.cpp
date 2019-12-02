#include <Main.h>
Motor motor;
Launcher launch;
void setup() 
{
    BoardInit();
    Serial.begin(38400);
    motor = Motor();   
    SERVO_Disable(0);
}

void loop()
{ 
  int state = 0;
  if(Serial.available()){
    state = Serial.read();
  }

  switch (state)
        {
        case '2':
            motor.turn(-1);//Tourne les moteurs à gauche
            delay(500);
            break;
        case '1':
            motor.turn(1);
            delay(500); 
            break;
        case '3':
            launch.launch(100);
            break;
        default:
            motor.stopMotors();
            break;
        }
}