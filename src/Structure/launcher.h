#include <Arduino.h>
#include <LibRobus.h>

struct Launcher
{
    void spin(int spinspeed){   
        analogWrite(2,spinspeed);
    }
    
    void idle(int idlespeed){
        analogWrite(2,idlespeed);
    }

    void stop(){
        analogWrite(2,0);
    }

    void serveball(){
        SERVO_Enable(0);
        SERVO_SetAngle(0,30);
        delay(200);   
        SERVO_Disable(0);
        }

    void launch(int spinspeed){
        spin(spinspeed);
        delay(4000);
        stop();
        serveball();
       }
};
