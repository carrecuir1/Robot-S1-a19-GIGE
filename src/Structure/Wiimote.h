#ifndef WIIMOTE_H
#define WIIMOTE_H

struct Wiimote {
    char address[6];
    Wiimote(){
        initAddress();
    }

    void initAddress(){
        //L'adresse doit être à l'envers
        address[5] = 0x40;
        address[4] = 0xD2;
        address[3] = 0x8A;
        address[2] = 0x5D;
        address[1] = 0xB6;
        address[0] = 0x10;
    }

    void getAction(){
        
    }

};

#endif