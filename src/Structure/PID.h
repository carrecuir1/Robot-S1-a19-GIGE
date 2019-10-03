#include <Arduino.h>
#include <LibRobus.h>

#define kP 0.00005
#define kI 0.000003 
//Robot 16B kP = 0.00005 kI = 0.000003
//Robot 16A kP = 
// Moteur gauche est esclave au moteur droit
struct PID {
    float speedML;
    float meterMotorL, meterMotorR; //Compteur de distance de chacun des moteurs

    PID(float consigne){
        speedML = consigne;
        meterMotorL = 0;
        meterMotorR = 0;
    }
    
    float getPID(){
        float motorR,motorL;

        motorR = ENCODER_ReadReset(1);
        motorL = ENCODER_ReadReset(0);

        meterMotorR += motorR;
        meterMotorL += motorL;

        float errorSpeed = kP*(motorR - motorL) + kI*(meterMotorR - meterMotorL); //On soustrait les deux encoders puis on multiplit par la valeur de kP.
        speedML = (speedML + errorSpeed);

        return speedML;        
    }
    
};