#include <Arduino.h>
#include <LibRobus.h>

#define kP 0.00001
#define kI 0.0000015
//Robot 16B kP = 0.00005 kI = 0.000005
//Robot 16A kP = 
// Moteur gauche est esclave au moteur droit
struct PID {
    float speedML;
    float meterMotorL, meterMotorR, oldMML, oldMMR, motorR, motorL; //Compteur de distance de chacun des moteurs

    PID(float consigne){
        speedML = consigne;
        meterMotorL = 0;
        meterMotorR = 0;
        motorR = 0;
        motorL = 0;
    }
    
    float getPID(){
        float diffL, diffR;

        oldMMR = motorR;
        oldMML = motorL;

        motorR = ENCODER_Read(1);
        motorL = ENCODER_Read(0);

        diffL = motorL - oldMML;
        diffR = motorR - oldMMR;

        meterMotorR += diffR;
        meterMotorL += diffL;

        float errorSpeed = kP*(diffR - diffL) + kI*(meterMotorR - meterMotorL); //On soustrait les deux encoders puis on multiplit par la valeur de kP.
        speedML = (speedML + errorSpeed);

        return speedML;        
    }
};