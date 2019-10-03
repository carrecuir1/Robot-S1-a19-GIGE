#include <Arduino.h>
#include <LibRobus.h>
#include <LibGny.h>

void avancerRobot(float distance)
{
    float diametre = 23.94;
    int distanceGauche, distanceDroite = 0;
    ENCODER_Reset(0);
    ENCODER_Reset(1);

    do
    {
        if(distanceDroite > (0.7*distance))
        {
            if(distanceDroite > (0.9*distance))
            {
                MOTOR_SetSpeed(0, 0.2);
                MOTOR_SetSpeed(1, 0.2);
                
                distanceGauche = (diametre * ENCODER_Read(0))/3200;
                distanceDroite = (diametre * ENCODER_Read(1))/3200;

                Serial.println("ralenti 2");
            }
            else
            {          
                MOTOR_SetSpeed(0, 0.3);
                MOTOR_SetSpeed(1, 0.3);
                
                distanceGauche = (diametre * ENCODER_Read(0))/3200;
                distanceDroite = (diametre * ENCODER_Read(1))/3200;

                Serial.println("ralenti");
            } 
        }
        else
       {
            MOTOR_SetSpeed(0, 0.5);
            MOTOR_SetSpeed(1, 0.5);
            
            distanceGauche = (diametre * ENCODER_Read(0))/3200;
            distanceDroite = (diametre * ENCODER_Read(1))/3200;

            Serial.println("avance");
        }
        
    }while(distanceDroite < distance && distanceGauche < distance);

     MOTOR_SetSpeed(0, 0);
     MOTOR_SetSpeed(1, 0);
}