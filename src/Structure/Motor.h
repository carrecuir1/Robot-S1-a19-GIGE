#include <Arduino.h>
#include <LibRobus.h>

//chiffre doit terminer par ".0" à cause du float
#define circumference 1168.672467
#define distancePulse 0.074809175064
#define diameter 23.94
#define RED 0
#define BLUE 1
#define YELLOW 2
#define GREEN 3

struct Motor {

    PID pid;

    Motor(){
        
    }
    
    #pragma region TurnFunctions
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
    void uTurn(float speed)
    {
        int32_t encoderL = 0, encoderR = 0;
        float pulseToAchieve = (180*circumference)/(360*distancePulse);
        PID pid = PID(speed);

        ENCODER_Reset(0);
        ENCODER_Reset(1);

        MOTOR_SetSpeed(0, speed);
        MOTOR_SetSpeed(1,-1*pid.getPID());

        while(encoderL-encoderR < pulseToAchieve-120) //-120 pour la marge d'erreur
        {
            encoderL = ENCODER_Read(0);
            encoderR = ENCODER_Read(1);
        }
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);

    }
   
    #pragma endregion TurnFunctions

    //Le robot avance pendant un temps indéfini
    void move(float speed){
        MOTOR_SetSpeed(1, speed);
        MOTOR_SetSpeed(0, speed);

    }
    void moveWithPID(float speed){
        resetPIDAndEncoder(speed);

        MOTOR_SetSpeed(1, speed);
        checkPID();
    }
    //Fonction qui avance sur une certaine distance
    //Mettre un chiffre négatif ou positif pour la direction (-1, 1)
    void moveDistance(float distance, float speed)
    {
        float distanceRight = 0;

        resetPIDAndEncoder(speed);

        MOTOR_SetSpeed(1, speed);
        do
        {
            checkPID();
            distanceRight = (diameter * ENCODER_Read(1))/3200;
        }
        while(distanceRight < distance);

        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);
    }
    void moveOverCircle(float distance)
    {
        ENCODER_Reset(0);
        ENCODER_Reset(1);
        float distanceRight = 0;
        MOTOR_SetSpeed(0, 0.3);
        MOTOR_SetSpeed(1, 0.3);
        do
        {
            distanceRight = (diameter * ENCODER_Read(1))/3200;
        }
        while(distanceRight < distance);

        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);
    }
    void findColor(char robotName, int color)
    {
        Motor motor;

        if(robotName == 'A')
        {
            switch (color)
            {

            case RED:
                motor.moveDistance(15, 0.4);
                moveOverCircle(17);
                motor.angleTurn(-45);
                moveOverCircle(17);
                break;

            case GREEN:
                motor.moveDistance(15, 0.4);
                moveOverCircle(17);
                motor.angleTurn(45);
                moveOverCircle(17);
                break;

             case BLUE:
                motor.angleTurn(45);
                motor.moveDistance(12, 0.4);
                motor.angleTurn(95);
                break;

            case YELLOW:
                motor.angleTurn(-45);
                motor.moveDistance(10, 0.4);
                motor.angleTurn(-95);
                break;
            default:
                break;
            }
        }
        else if(robotName == 'B')
        {
            switch (color)
            {
            case BLUE:
                motor.angleTurn(45);
                motor.moveDistance(12, 0.4);
                motor.angleTurn(-90);  
                moveOverCircle(31);
                break;

            case YELLOW:
                motor.angleTurn(-45);
                motor.moveDistance(12, 0.4);
                motor.angleTurn(90);
                moveOverCircle(31);
                break;

             case RED:
                motor.angleTurn(-90);
                motor.moveDistance(15, 0.4);
                motor.angleTurn(90);
                motor.moveDistance(31, 0.4);
                motor.angleTurn(135);
                moveOverCircle(31);
                break;

            case GREEN:
                motor.angleTurn(90);
                motor.moveDistance(15, 0.4);
                motor.angleTurn(-90);
                motor.moveDistance(31, 0.4);
                moveOverCircle(31);
                break;
                
            default:
                break;
            }
        }
        else
        {
            Serial.print("Invalid robot name");
        }
        
    }

    //Va reset le pid et les encodeurs
    void resetPIDAndEncoder(float consigne){
        ENCODER_Reset(0);
        ENCODER_Reset(1);
        pid = PID(consigne);
    }

    //Fonction qui va regarder le PID et changer la vitesse du motorGauche
    void checkPID(){
        MOTOR_SetSpeed(0, pid.getPID());
    }

    void stopMotors(){
        MOTOR_SetSpeed(0,0);
        MOTOR_SetSpeed(1,0);
    }

};