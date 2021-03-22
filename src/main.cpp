#include<wiringPi.h>
 
int main(void)
{
    wiringPiSetupGpio();
    pinMode(18,PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetRange(2000);
    pwmSetClock(192);
     
    while(1)
    {
    pwmWrite(18,180);
    }
    return 0;
}
