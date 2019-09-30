#include <Arduino.h>
#include <LibRobus.h>

struct Motor {
    
    Motor(){

    }
    
    void angleTurn(int8_t angle, int8_t consigne){
        MOTOR_SetSpeed(0,consigne);
        MOTOR_SetSpeed(1,-consigne);
        int32_t encoderL = ENCODER_ReadReset(0);
    }

    void straitRun(){

    }

    
};