#include <Arduino.h>
#include <LibRobus.h>

struct Launcher
{
    void spin(int spinspeed){
        analogWrite(10,spinspeed); 
    }

    void idle(int idlespeed){
        analogWrite(10,idlespeed);
    }

    void stop(){
        analogWrite(10,0);
    }

    void serveball(){
        SERVO_Enable(0);
        SERVO_SetAngle(0,45);
        delay(250);
        SERVO_SetAngle(0,90);
        SERVO_Disable(0);
    }

    void launch(int spinspeed){
        spin(spinspeed);
        delay(500);
        serveball();
        stop();
    }
};
