#include <Arduino.h>
#include <LibRobus.h>

#define kP 0.000001
#define kI 0.0000002
// Moteur gauche est esclave au moteur droit
struct PID {
    int32_t speedML;
    float meterMotorL, meterMotorR; //Compteur de distance de chacun des moteurs
    int index;

    PID(int8_t consigne){
        index = 1;
        speedML = consigne;
        meterMotorL = 0;
        meterMotorR = 0;
    }
    
    int32_t getPID(){
        int32_t motorR,motorL;

        motorR = ENCODER_ReadReset(1);
        motorL = ENCODER_ReadReset(0);

        meterMotorR += motorR;
        meterMotorL += motorL;

        float errorSpeed = kP*(motorR - motorL) + kI*(meterMotorR - meterMotorL); //On soustrait les deux encoders puis on multiplit par la valeur de kP.
        speedML = (speedML + errorSpeed);
        
        index++;

        return speedML;        
    }
    
};