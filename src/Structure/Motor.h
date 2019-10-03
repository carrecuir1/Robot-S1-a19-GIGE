#include <Arduino.h>
#include <LibRobus.h>

#define circumference 1171.1814059789
#define distancePulse 0.074809175064

struct Motor {
    
    Motor(){
        
    }
    
    void angleTurn(float angle, float consigne){
        int selectEncodeur = 0;
        int32_t encoder = 0;
        float pulseToAchieve = (angle*circumference)/(360*distancePulse);

        if(angle < 0){
            selectEncodeur = 1;
        }
        
        ENCODER_Reset(selectEncodeur);
        MOTOR_SetSpeed(selectEncodeur,consigne);
        
        while(encoder < pulseToAchieve){
            encoder = ENCODER_Read(selectEncodeur);
        }
        MOTOR_SetSpeed(selectEncodeur,0);
    }

    void straightRun(){

    }

    
};