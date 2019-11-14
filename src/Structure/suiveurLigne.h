#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/Motor.h>
#include <Structure/capteurIR.h>

#define voltageNoirM 4.60 //Valeur de tension associable à une couleur noire captée par le capteur, un peu arbitraire.
#define voltageNoirD 4.40
#define voltageNoirG 3.30

struct suiveurLigne{
    //Capteur avant sur port analogique 0, milieu sur 1, arrière sur 2.
    float voltage[3];

    void detection(float voltage[3]){
    
        voltage[0] = analogRead(4)*5.0/1023.0;
        voltage[1] = analogRead(5)*5.0/1023.0;
        voltage[2] = analogRead(6)*5.0/1023.0;
    }

    void suivreLigneDroite()
    {
            capteurIR capteur;
            float voltage[3];
            detection(voltage);
            Motor moteur;
            moteur.resetPIDAndEncoder(0.2);
            moteur.move(0.2);
        while(capteur.getDistance()>36){
            Serial.println("test");
                
                if(voltage[0]>=voltageNoirG && voltage[1]<voltageNoirM && voltage[2]<voltageNoirD){
                    MOTOR_SetSpeed(0, 0.05);
                    MOTOR_SetSpeed(1,0.2);
                    while(voltage[0]>=voltageNoirG && voltage[1]<voltageNoirM && voltage[2]<voltageNoirD){
                        delay(50);
                        detection(voltage);
                    }
                    moteur.stopMotors();
                    delay(50);
                }
                else{

                    if(voltage[2]>=voltageNoirD && voltage[0]<voltageNoirG && voltage[1]<voltageNoirM){
                        MOTOR_SetSpeed(0, 0.2);
                        MOTOR_SetSpeed(1, 0.05);
                        while(voltage[2]>=voltageNoirD && voltage[1]<voltageNoirM && voltage[0]<voltageNoirG){
                            delay(50);
                            detection(voltage);
                        }
                        moteur.stopMotors();
                        delay(50);
                    }
                    else{
                        if(voltage[0]>=voltageNoirG && voltage[1]>=voltageNoirM && voltage[2]<voltageNoirD){
                            MOTOR_SetSpeed(0, 0.05);
                            MOTOR_SetSpeed(1,0.2);
                            while(voltage[0]>=voltageNoirG && voltage[1]>=voltageNoirM && voltage[2]<voltageNoirD){
                                delay(50);
                                detection(voltage);
                            }
                            moteur.stopMotors();
                            delay(50);
                        }
                        else{
                            if(voltage[0]<voltageNoirG && voltage[1]>=voltageNoirM && voltage[2]>=voltageNoirD){
                                MOTOR_SetSpeed(0, 0.2);
                                MOTOR_SetSpeed(1, 0.05);
                                while(voltage[2]>=voltageNoirD && voltage[1]>=voltageNoirM && voltage[0]<voltageNoirG){
                                    delay(50);
                                    detection(voltage);
                                }
                                moteur.stopMotors();
                                delay(50);
                            }
                            else{
                                if(voltage[0]>=voltageNoirG && voltage[1]>=voltageNoirM && voltage[2]>=voltageNoirD){
                                    moteur.angleTurn(1);
                                }
                                else
                                    moteur.move(0.2);
                            }
                        }
                    }
                }
                 detection(voltage);
            }
            moteur.stopMotors();
        }; 
  };