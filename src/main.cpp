#include <wiringPi.h>
#include <unistd.h>
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
	//usleep(20000);
	usleep(17500);
	digitalWrite (26, HIGH);
	usleep(2500);
	digitalWrite (26,  LOW);
	//cout << i << endl;
      }
    } else {
      for (int i = 0; i <= 50; i++) {
	//usleep(20000);
	usleep(19500);
	digitalWrite (26, HIGH);
	usleep(500);
	digitalWrite (26,  LOW);
	//cout << i << endl;
      }
    }
    //cout << "FIRE!" << endl;
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

  while (true) {
    int degrees;
    string direction;
    cout << "richting: ";
    cin >> direction;
    if (direction == "s") {
      cout << vertical_new << endl;
      if ((vertical_new - 10) >= vertical_min) {
	vertical_old = vertical_new;
	vertical_new = vertical_new - interval;
      }
      cout << vertical_new << endl;
    } else if (direction == "w") {
      cout << vertical_new << endl;
      if ((vertical_new + 10) <= vertical_max) {
	vertical_old = vertical_new;
	vertical_new = vertical_new + interval;
      }
      cout << vertical_new << endl;
    } else if (direction == "a") {
      cout << horizontal_new << endl;
      if ((horizontal_new - 10) >= horizontal_min) {
	horizontal_old = horizontal_new;
	horizontal_new = horizontal_new - interval;
      }
      cout << horizontal_new << endl;
    } else if (direction == "d") {
      cout << horizontal_new << endl;
      if ((horizontal_new + 10) <= horizontal_max) {
	horizontal_old = horizontal_new;
	horizontal_new = horizontal_new + interval;
      }
      cout << horizontal_new << endl;
    } else if (direction == "f") {
      if (fire == false) {
	fire = true;
      } else {
	fire = false;
      }
    } else {
      cout << "geen geldige input \n";
    }
    if (degrees == -1) {
      break;
    }
  }
  return(0);
}
