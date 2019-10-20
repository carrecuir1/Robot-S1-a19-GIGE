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
    
    //Fonction qui permet de tourner avec un moteur
    void angleTurn(float angle){
        int selectEncodeur = 0;
        int32_t encoder = 0;
        float pulseToAchieve = 0.95*((abs(angle)*circumference)/(360*distancePulse));

        if(angle < 0){
            selectEncodeur = 1;
        }
        
        ENCODER_Reset(selectEncodeur);
        MOTOR_SetSpeed(selectEncodeur, 0.2);
        
        while(abs(encoder) < pulseToAchieve){
            encoder = ENCODER_Read(selectEncodeur);
        }
        MOTOR_SetSpeed(selectEncodeur,0);
        Serial.println(encoder);
        Serial.println(pulseToAchieve);
    }

    //Fonction qui permet de faire un u-turn avec les deux moteurs
    void uTurn()
    {
        PID pid = PID(speed);

        float pulseToAchieve = (180*circumference)/(360*distancePulse);
        int32_t encoderL = 0, encoderR = 0;
        ENCODER_Reset(0);
        ENCODER_Reset(1);

        MOTOR_SetSpeed(0, speed);
        MOTOR_SetSpeed(1,-1*pid.getPID());

        while(encoderL-encoderR < pulseToAchieve-120)
        {
            encoderL = ENCODER_Read(0);
            encoderR = ENCODER_Read(1);
        }
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);

    }
   
    //Permet d'avancer
    void moveFront(float distance)
    {
        moveDistance(distance, 1);
    }

    //Permet de reculer
    void moveBack(float distance)
    {
        moveDistance(distance, -1);
    }
    
    //Fonction qui avance sur une certaine distance
    void moveDistance(float distance, int8_t direction)
    {
        float directionSpeed = speed * direction;
        float distanceRight = 0;
        PID motor(directionSpeed);
        ENCODER_Reset(0);
        ENCODER_Reset(1);
        MOTOR_SetSpeed(1, directionSpeed);
        do
        {
            MOTOR_SetSpeed(0, motor.getPID());
            distanceRight = (diameter * ENCODER_Read(1))/3200;   
        }
        while(distanceRight < distance);

        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);
    }
};