#include <iostream>
#include <wiringPi.h>

using namespace std;

int afstand(int Trig, int Echo) {
  wiringPiSetup();
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);

  digitalWrite (Trig, 1);
  delay(10);
  digitalWrite (Trig, 0);


  while (digitalRead(Echo) == 0) {}
  float StartTime = micros(); // Begin tijd van echo

  while (digitalRead(Echo) == 1) {}
  float EndTime = micros(); // Eind tijd van echo


  float difference = EndTime - StartTime; // De tijd dat de echo nodig had om terug te komen in micro seconden
  float distance =  ((difference / 2) *34300) / 1000000; // de afstand met een formule berekend

  return distance;
}

int main() {
  int TrigPin = 15; //GPIO pin die verbonden is met de "trig" van de sensor
  int EchoPin = 16; //GPIO pin die verbonden is met de "echp" van de sensor
  while( true) {
    cout << "aftsand in cm is: " <<  afstand(TrigPin, EchoPin) << "\n";
    delay(1000);
  }
}
