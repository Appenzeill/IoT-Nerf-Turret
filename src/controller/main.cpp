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

// handmatige implementatie van pwm signal.
PI_THREAD(fire_servo) {
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

PI_THREAD(vertical_servo) {
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

PI_THREAD(horizontal_servo) {
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

void onrecieve(string message) {
  int interval = 5;
  if (message == "schiet") {
    if (fire == false) {
      fire = true;
    } else {
      fire = false;
    }
  } else if (message == "omlaag") {
    if ((vertical_new + 10) <= vertical_max) {
      vertical_old = vertical_new;
      vertical_new = vertical_new + interval;
    }
  } else if (message == "omhoog") {
    if ((vertical_new - 10) >= vertical_min) {
      vertical_old = vertical_new;
      vertical_new = vertical_new - interval;
    }
  } else if (message == "links") {
    if ((horizontal_new + 10) <= horizontal_max) {
      horizontal_old = horizontal_new;
      horizontal_new = horizontal_new + interval;
    }
  } else if (message == "rechts") {
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

  // hoeveel punten per keer met draaien.
  int interval = 5;

  // error handling van de threads
  if (t0 != 0 || t1 != 0 || t2 != 0 ) {
    std::cout << "threads did not start correctly." << std::endl;
  }
  
  wiringPiSetupGpio();
  // schiet servo
  pinMode (26, OUTPUT);

  // pwm servos
  pinMode(18,PWM_OUTPUT); // 18
  pinMode(19,PWM_OUTPUT); // 19
  
  pwmSetMode(PWM_MODE_MS);
  pwmSetRange(2000);
  pwmSetClock(192);

  // pubsub configuratie
  subscription s("Turret_controller7", onrecieve);

  cout << "waiting for messages" << endl;
  cout << "druk op de \'s\' knop om te stoppen"  << endl;
  cin.get();

  return(0);
}
