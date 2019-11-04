#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/Motor.h>

#define voltageNoir 4.0 //Valeur de tension associable à une couleur noire captée par le capteur, un peu arbitraire.
#define voltageCouleur 2.0 //Valeur située au-dessus du voltage pour le blanc, plus petit voltage entre jaune, rouge, bleu, vert.

struct suiveurLigne{
    //Capteur avant sur port analogique 0, milieu sur 1, arrière sur 2.
    float voltage[3];

    void detection(float voltage[3]){
        voltage[0] = analogRead(0)*5.0/1023.0;
        voltage[1] = analogRead(1)*5.0/1023.0;
        voltage[2] = analogRead(2)*5.0/1023.0;
    }

    void detecterLigne(){
        Motor moteur;
        moteur.move(0.2);
        while(voltage[1]<voltageNoir){
            detection(voltage);
        }
        moteur.stopMotors();
    }

    void suivreLigneDroite()
    {
        float voltage[3];
        float encodeur_droit = 0,encodeur_gauche = 0;
        
        Motor moteur;
        while(!ROBUS_IsBumper(0) && !ROBUS_IsBumper(1) && !ROBUS_IsBumper(2)){
            
            if(voltage[1] <= voltageNoir){
                moteur.move(0.2);
            }
            else{
                
                if(voltage[0]<=voltageNoir && voltage[1]>voltageNoir){
                    moteur.turnMoving(-1,0.2, 0.02);
                    //Tourner en avançant vers la gauche
                }
                else{

                    if(voltage[2]<=voltageNoir && voltage[1]>voltageNoir){
                        moteur.turnMoving(1,0.2 , 0.02);
                        //Tourner en avançant vers la droite
                    }
                    
                }
            }
            detection(voltage);
            delay(100);            
            
            if(voltage[0]>=voltageNoir && voltage[1]>=voltageNoir && voltage[2]>=voltageNoir){
                moteur.move(0.2);
            }
        }
    };
};