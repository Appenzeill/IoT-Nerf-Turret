#include <iostream>
#include <wiringPi.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "pubsub.h"
#include <string>
#include <vector>
using namespace std;

#define L 27
#define R 17
#define S 16
#define Blue 21
#define Red 20
#define Yellow 26

void setup(){
    //Alle leds worden hier op de juiste mode gezet dus input/output
    wiringPiSetupGpio();
    pinMode(L, INPUT);
    pinMode(R, INPUT);
    pinMode(S, INPUT);
    pinMode(Blue, OUTPUT);
    pinMode(Red, OUTPUT); 
    pinMode(Yellow, OUTPUT);
}
void leds(vector<int> values = {0,0,0}){
    //indicator leds voor welke mode de gebruiker zich bevindt. 
    if(values[2] == 1){
        digitalWrite(Blue, HIGH);
    }else{
        digitalWrite(Blue, LOW);
    }
    if(values[1] == 1){
        digitalWrite(Red, HIGH);
    }else{
        digitalWrite(Red, LOW);
    }
    if(values[0] == 1){
            digitalWrite(Yellow, HIGH);
    }else{
        digitalWrite(Yellow, LOW);
    }
}

void knoppen(bool keuze){
    publisher p("Turret_controller7");
    while(!digitalRead(S)){
        if(keuze == true){ //keuze is verticaal
            if(digitalRead(L)){  
                //cout << "Omhoog +=1" << endl; 
                p.send("omhoog");
                delay(200);
            }else if(digitalRead(R)){
                //cout << "omlaag +=1" << endl;
                p.send("omlaag");
                delay(200);
            }
        }else{ //keuze is horizontaal
            if(digitalRead(L)){
                //cout << "Links +=1" << endl;
                p.send("links");
                delay(200);
            }else if(digitalRead(R)){
                //cout << "rechts +=1" << endl;
                p.send("rechts");
                delay(200);
            }
        }
    }
    delay(200);
    cout << "Terug naar keuzes" << endl; //terug knop wordt ingedrukt zodat de gebruiker weer naar het start-'scherm' kan. 
}
int main(void){
    setup();
    cout << "De keuzes voor de controller zijn \nKnop 1 links/rechts, Knop 2 omhoog/omlaag, knop 3 schieten."<< endl;
    while(true){
        leds({0,0,1}); //leds staan op start mode
        if(digitalRead(L)){ //keuze is horizontaal, leds worden aangepast naar H, en de keuzes worden meegegeven aan de knoppen functie voor verder gebruik
            cout << "Druk op knop 1 om naar links te draaien, druk op knop 2 om naar rechts te draaien, knop 3 voor terug te gaan" << endl;
            delay(200);
            leds({1,0,0});
            knoppen(0);
        }else if(digitalRead(R)){ //keuze is verticaal, leds worden aangepast naar V, knoppen functie wordt aangeroepen met de juiste parameters
            cout << "Druk op knop 1 om naar omhoog te draaien, druk op knop 2 om naar omlaag te draaien, knop 3 voor terug te gaan" << endl;
            delay(200);
            leds({0,1,0});
            knoppen(1);
        }else if(digitalRead(S)){ //schiet keuze, alle leds gaan uit, en het programma eindigt. Hier wordt een extra delay toegevoegd voor als de terugknop in andere modes te lang word ingedrukt.
            delay(200);
            leds({0,0,0});
            cout << "Geschoten!!!!" << endl;
            publisher p("Turret_controller7");
            p.send("schiet");
            exit(0);
        }
    }
}
