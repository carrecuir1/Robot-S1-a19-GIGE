#include <Arduino.h>
#include <LibRobus.h>

//chiffre doit terminer par ".0" à cause du float
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
        int selectMotor = 0; //Le moteur qui doit tourner. 
        int32_t encoder = 0;
        float pulseToAchieve = 0.95*((abs(angle)*circumference)/(360*distancePulse)); //il faisait un angle trop grand. On a du mettre une petite patch de 0.95

        if(angle < 0){
            selectMotor = 1;
        }

        ENCODER_Reset(selectMotor);
        MOTOR_SetSpeed(selectMotor, 0.2);

        while(abs(encoder) < pulseToAchieve){
            encoder = ENCODER_Read(selectMotor);
        }

        MOTOR_SetSpeed(selectMotor,0);
    }

    //Fonction qui permet de faire un u-turn avec les deux moteurs
    void uTurn()
    {
        int32_t encoderL = 0, encoderR = 0;
        float pulseToAchieve = (180*circumference)/(360*distancePulse);
        PID pid = PID(speed);

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
   
    //Permet d'avancer dans un temps indéfini
    void moveFoward(PID *motor){

    }

    //Permet de reculer dans un temps indéfini
    void moveBackward(PID *motor){

    }
    
    #pragma region Move a distance Functions
    //Permet d'avancer selon une distance entrée
    void moveFoward(float distance)
    {
        moveDistance(distance, 1);
    }

    //Permet de reculer selon une distance entrée
    void moveBackward(float distance)
    {
        moveDistance(distance, -1);
    }
    
    //Fonction qui avance sur une certaine distance
    void moveDistance(float distance, int8_t direction)
    {
        float distanceRight = 0;
        float directionSpeed = speed * direction;
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
    #pragma endregion Move a distance Functions
};