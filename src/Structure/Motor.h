#include <Arduino.h>
#include <LibRobus.h>

//chiffre doit terminer par ".0"
#define circumference 1168.672467
#define distancePulse 0.074809175064
#define diameter 23.94

struct Motor {
    
    float speed;

    Motor(float consigne){
        speed = consigne;
    }
    
    void angleTurn(float angle){
        int selectEncodeur = 0;
        int32_t encoder = 0;
        float pulseToAchieve = 0.95*((abs(angle)*circumference)/(360*distancePulse));

        if(angle < 0){
            selectEncodeur = 1;
        }
        
        ENCODER_Reset(selectEncodeur);
        MOTOR_SetSpeed(selectEncodeur, 0.25);
        
        while(abs(encoder) < pulseToAchieve){
            encoder = ENCODER_Read(selectEncodeur);
        }
        MOTOR_SetSpeed(selectEncodeur,0);
        Serial.println(encoder);
        Serial.println(pulseToAchieve);
    }

    void uTurn()
    {
        PID pid = PID(speed);

        float pulseToAchieve = (180*circumference)/(360*distancePulse);
        int32_t encoderL = 0, encoderR = 0;
        ENCODER_Reset(0);
        ENCODER_Reset(1);

        MOTOR_SetSpeed(0, speed);
        MOTOR_SetSpeed(1,-1*pid.getPID());

        //while(encoderL < pulseToAchieve && -1*encoderR < pulseToAchieve)
        while(encoderL-encoderR < pulseToAchieve-120)
        {
            encoderL = ENCODER_Read(0);
            encoderR = ENCODER_Read(1);
        }
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);

    }
   
    void straightRun(float distance)
    {
        float distanceRight = 0;
        PID motor(speed);
        ENCODER_Reset(0);
        ENCODER_Reset(1);
        do
        {
            Serial.println(speed);
            Serial.println(motor.getPID());

            MOTOR_SetSpeed(1, speed);
            MOTOR_SetSpeed(0, motor.getPID());
            distanceRight = (diameter * ENCODER_Read(1))/3200;
            
        }while(distanceRight < distance);
        Serial.println(distanceRight);

        Serial.println("arriver");
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);
    }
};