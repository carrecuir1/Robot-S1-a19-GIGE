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
        delay(300);
        SERVO_SetAngle(0,100);
        delay(250);
    }

    void launch(int spinspeed){
        spin(spinspeed);
        delay(500);
        serveball();
        delay(500);
        stop();
    }
};
