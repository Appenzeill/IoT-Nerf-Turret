#include <wiringPi.h>
#include <unistd.h>
#include "pubsub.h"
#include <iostream>

using namespace std;

bool fire = false;

int horizontal_new = 130;
int horizontal_old = 130;
int horizontal_min = 30;
int horizontal_max = 260;

int vertical_min = 80;
int vertical_max = 160;
int vertical_new = 120;
int vertical_old = 120;

PI_THREAD(fire_servo) { // handmatige implementatie van pwm signal voor de servo die schiet.
  while (true) {
    if (fire == false) {
      for (int i = 0; i <= 50; i++) {
	usleep(19500);
	digitalWrite (26, HIGH);
	usleep(500);
	digitalWrite (26,  LOW);
      }
    } else {
      for (int i = 0; i <= 50; i++) {
	usleep(17500);
	digitalWrite (26, HIGH);
	usleep(2500);
	digitalWrite (26,  LOW);
      }
    }
  }
  return(0);
}

PI_THREAD(vertical_servo) { // handmatige implementatie van pwm signal voor de servo die verticaal beweegd.
  while (true) {
    usleep(30000);
    if (horizontal_new != vertical_old && vertical_new < vertical_old) {
      for (int i = vertical_old; i >= vertical_new; i--) {
	usleep(10000);
	pwmWrite(19,i); // 18, 50
      }
    } else if (vertical_new != vertical_old && vertical_new > vertical_old) {
      for (int i = vertical_old; i <= vertical_new; i++) {
	usleep(10000);
	pwmWrite(19,i); // 18, 50
      }
    }
    vertical_old = vertical_new;
  }
  return(0);
}

PI_THREAD(horizontal_servo) { // handmatige implementatie van pwm signal voor de servo die horizontaal beweegd.
  while (true) {
    usleep(30000);
    if (horizontal_new != horizontal_old && horizontal_new < horizontal_old) {
      //cout << "kleiner \n";
      for (int i = horizontal_old; i >= horizontal_new; i--) {
	usleep(10000);
	pwmWrite(18,i); // 18, 50
      }
    } else if (horizontal_new != horizontal_old && horizontal_new > horizontal_old) {
      //cout << "groter \n";
      for (int i = horizontal_old; i <= horizontal_new; i++) {
	usleep(10000);
	pwmWrite(18,i); // 18, 50
      }
    }
    horizontal_old = horizontal_new;
  }
  return(0);
}

void onrecieve(string message) { // hier ontvangt de code het bericht dat verstuurd is via Pubsub2
  int interval = 5;
  if (message == "schiet") { // Als het bericht van Pubsub 'schiet' is, wordt fire true, zodat de Pi_THREAD de schiet-servo draait.
    if (fire == false) {
      fire = true;
    } else {
      fire = false;
    }
  } else if (message == "omlaag") { // Als het bericht van Pubsub 'omlaag' is, wordt er bij vertical_old 10 graden bijgedaan, zodat de Pi_THREAD de verticale servo draait.
    if ((vertical_new + 10) <= vertical_max) {
      vertical_old = vertical_new;
      vertical_new = vertical_new + interval;
    }
  } else if (message == "omhoog") { // Als het bericht van Pubsub 'omhoog' is, wordt er bij vertical_old 10 graden afgehaalt, zodat de Pi_THREAD de verticale servo draait.
    if ((vertical_new - 10) >= vertical_min) {
      vertical_old = vertical_new;
      vertical_new = vertical_new - interval;
    }
  } else if (message == "links") { // Als het bericht van Pubsub 'links' is, wordt er bij horizontal_old 10 graden bijgedaan, zodat de Pi_THREAD de horizontale servo draait.
    if ((horizontal_new + 10) <= horizontal_max) {
      horizontal_old = horizontal_new;
      horizontal_new = horizontal_new + interval;
    }
  } else if (message == "rechts") { // Als het bericht van Pubsub 'rechts' is, wordt er bij horizontal_old 10 graden afgehaalt, zodat de Pi_THREAD de horizontale servo draait.
    if ((horizontal_new - 10) >= horizontal_min) {
      horizontal_old = horizontal_new;
      horizontal_new = horizontal_new - interval;
    }
  }
}

int main(void) {
  // initialiseer de threads.
  int t0 = piThreadCreate(vertical_servo);
  int t1 = piThreadCreate(horizontal_servo);
  int t2 = piThreadCreate(fire_servo);

  int interval = 5; // hoeveel graden de servo per keer draaien.

  if (t0 != 0 || t1 != 0 || t2 != 0 ) { // error handling van de threads
    std::cout << "threads did not start correctly." << std::endl;
  }
  
  wiringPiSetupGpio();
  pinMode(26, OUTPUT); // schiet servo GPIO pin 26

  // pwm servos
  pinMode(18,PWM_OUTPUT); // GPIO pin 18
  pinMode(19,PWM_OUTPUT); // GPIO pin 19
  
  pwmSetMode(PWM_MODE_MS);
  pwmSetRange(2000);
  pwmSetClock(192);

  subscription s("Turret_controller7", onrecieve); // pubsub configuratie

  cout << "waiting for messages" << endl;
  cout << "druk op de \'s\' knop om te stoppen"  << endl;
  cin.get();

  return(0);
}
