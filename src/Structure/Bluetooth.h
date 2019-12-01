#include <Arduino.h>
#include <LibRobus.h>

#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#define ledPin 

SoftwareSerial BTSerial(1, 0); // RX | TX

struct Bluetooth {

    Bluetooth(){
        Serial.begin(38400); // Default communication rate of the Bluetooth module
    }

    int read(){
        int state = -1;
        if(Serial.available() > 0){ // Checks whether data is comming from the serial port
            state = Serial.read(); // Reads the data from the serial port
            
        }
        return state;
    }

    void sendMessage(char message[]){
        Serial.println(message); // Send back, to the phone, the String "LED: ON"
    }
};

#endif