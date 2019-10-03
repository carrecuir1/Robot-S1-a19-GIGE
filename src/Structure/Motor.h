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

    void straightRun(float distance, float consigne)
    {
        float diameter = 23.94;
        float distanceRight = 0;
        PID motor(consigne);
        ENCODER_Reset(0);
        ENCODER_Reset(1);
        do
        {
           /*if(distanceRight > (0.7*distance))
            {
                if(distanceRight > (0.9*distance))
                {
                    MOTOR_SetSpeed(0.2, consigne);
                    MOTOR_SetSpeed(0, motor.getPID());
                    distanceRight = (diameter * ENCODER_Read(1))/3200;

                    Serial.println("ralenti 2");
                }
                else
                {          
                    MOTOR_SetSpeed(1, 0.3);
                    MOTOR_SetSpeed(0, motor.getPID());
                    distanceRight = (diameter * ENCODER_Read(1))/3200;

                    Serial.println("ralenti");
                } 
            }
            else*/
           // {
                Serial.println(consigne);
                Serial.println(motor.getPID());

                MOTOR_SetSpeed(1, consigne);
                MOTOR_SetSpeed(0, motor.getPID());
                distanceRight = (diameter * ENCODER_Read(1))/3200;

                Serial.println(distanceRight);
                Serial.println("avance");
           // }
            
        }while(distanceRight < distance);

        Serial.println("arriver");
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);
    }
};