#include <wiringPi.h>
#include <iostream>

using namespace std;

int main() {
  string servo_axis;
  int servo_degrees, pin;
  cout << "Axis: (xy/z) ";
  cin >> servo_axis;
  cout << "Servo graden: ";
  cin >> servo_degrees;

  wiringPiSetupGpio();
  if (servo_axis == "xy") {
    pinMode(18,PWM_OUTPUT); // 18
    pin = 18;
  } else {
    pinMode(19,PWM_OUTPUT); // 19
    pin = 19;
    
  }
  pwmSetMode(PWM_MODE_MS);
  pwmSetRange(2000);
  pwmSetClock(192);
  
  while(1) {
    pwmWrite(pin,servo_degrees); // 18, 50
  }
  return 0;
}
