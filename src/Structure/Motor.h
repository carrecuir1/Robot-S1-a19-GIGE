#include <Arduino.h>
#include <LibRobus.h>

struct Motor {
    
    Motor(){

    }
    
    void angleTurn(int8_t angle, int8_t consigne){
        consigne *= ((0 < angle) - (angle < 0)); // Va chercher le signe de l'angle et l'applique à la consigne
        MOTOR_SetSpeed(0,consigne);
        MOTOR_SetSpeed(1,-consigne);
        int32_t encoderL = ENCODER_ReadReset(0);
        while(encoderL < (angle*10)){ // 1 degré = 10 pulse
            encoderL = ENCODER_Read(0);
            delay(100);
        }
        MOTOR_SetSpeed(0,0);
        MOTOR_SetSpeed(1,0);
    }

    void straitRun(){

    }

    
};