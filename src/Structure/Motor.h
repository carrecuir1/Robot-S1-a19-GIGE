#include <Arduino.h>
#include <LibRobus.h>

#define circumference 1169.0 //chiffre doit terminer par ".0"
#define distancePulse 0.074809175064

struct Motor {
    
    Motor(){
        
    }
    
    void angleTurn(float angle, float consigne){
        int selectEncodeur = 0;
        int32_t encoder = 0;
        float pulseToAchieve = (abs(angle)*circumference)/(360*distancePulse);

        if(angle < 0){
            selectEncodeur = 1;
        }
        
        ENCODER_Reset(selectEncodeur);
        MOTOR_SetSpeed(selectEncodeur,consigne);
        
        while(abs(encoder) < pulseToAchieve){
            encoder = ENCODER_Read(selectEncodeur);
        }
        MOTOR_SetSpeed(selectEncodeur,0);
    }

    void straitRun(){
    }

    void demiTour(float consigne)
    {
        /*float pulseToAchieve = (90*circumference)/(360*distancePulse);
        int32_t encoder0 = 0, encoder1 = 0;
        ENCODER_Reset(0);
        ENCODER_Reset(1);

        MOTOR_SetSpeed(0,consigne);
        MOTOR_SetSpeed(1,-1*consigne);

        while(encoder0 < pulseToAchieve && -1*encoder1 < pulseToAchieve)
        {
            encoder0 = ENCODER_Read(0);
            encoder1 = ENCODER_Read(1);
        }
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);

        */

       
        /* angleTurn(90,consigne);
        delay(200);
        angleTurn(-89,-1*consigne);    //-1 degre pour 180 bien fait
        */
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