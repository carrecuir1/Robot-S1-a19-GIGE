#include <Arduino.h>
#include <LibRobus.h>
#include <Structure/PID.h>
#include <Structure/Motor.h>

#define voltageNoir 5 //Valeur de tension associable à une couleur noire captée par le capteur, un peu arbitraire.
#define voltageCouleur 3 //Valeur située au-dessus du voltage pour le blanc, plus petit voltage entre jaune, rouge, bleu, vert.

struct suiveurLigne{
    //Capteur avant sur port analogique 0, milieu sur 1, arrière sur 2.
    float voltage[3];

    void detection(float voltage[3]){
    
        voltage[0] = analogRead(0)*5.0/1023.0;
        voltage[1] = analogRead(1)*5.0/1023.0;
        voltage[2] = analogRead(2)*5.0/1023.0;
    }

    void suivreLigneDroite(float voltage[3])
    {
        while(0){
            detection(voltage);
            //Si les trois capteurs voient la ligne noire
            while(voltage[0]>=voltageNoir && voltage[1]>=voltageNoir && voltage[2]>=voltageNoir){
            
                Motor.straightRun(10); //Valeur de 10 peut-être à revoir, arbitraire
                detection(voltage);
            }

            //Si le capteur central voit la ligne noire mais que les deux autre capteurs non
            if(voltage[1]>=voltageNoir && (voltage[0]<voltageNoir || voltage[2]<voltageNoir){
            
                ENCODER_Reset(0);
                ENCODER_Reset(1);
                //Tourne à gauche jusqu'à ce qu'il trouve, pour un max de 90 degrés.
                while(voltage[0]<voltageNoir || voltage[1]<voltageNoir || voltage[2]<voltageNoir || condition){ //condition = quart de tour à gauche, **à coder**
                
                    Motor.angleTurn(-3); //Valeurs de ±3 peut-être à revoir, parfaitement arbitraire
                    detection(voltage);
                }
                //Après le quart de tour à gauche, si pas trouvé la ligne, refait la même opération vers la droite.
                if(voltage[0]<voltageNoir || voltage[1]<voltageNoir || voltage[2]<voltageNoir){

                    Motor.angleTurn(90);
                    ENCODER_Reset(0);
                    ENCODER_Reset(1);
                    while(voltage[0]<voltageNoir||voltage[1]<voltageNoir||voltage[2]<voltageNoir||condition){ //condition = quart de tour à droite, **à coder**
                    
                        Motor.angleTurn(3);
                        detection(voltage);
                    }
                }

            }
            //Si le capteur de l'avant voit la ligne noire mais que les deux autres capteurs non
            if(voltage[0]>=voltageNoir && voltage[2]<voltageNoir && voltage[1]<voltageNoir){
                while(voltage[1]<voltageNoir){
                    Motor.straightRun(10); //Avance jusqu'à ce que le capteur central voie la ligne noire.
                    detection(voltage);
                }

            }

            //Si le capteur arrière voit la ligne noire mais que les deux autres capteurs non
            if(voltage[2]>=voltageNoir && voltage[1]<voltageNoir && voltage[0]<voltageNoir){
                while(voltage[1]<voltageNoir){
                    Motor.straightRun(-10); //Recule jusqu'à ce que le capteur central voie la ligne noire.
                    detection(voltage);
                }
                
            }
        }
        
    }

};