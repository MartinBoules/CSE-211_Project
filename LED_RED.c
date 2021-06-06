#include "tm4c123gh6pm.h"

void LED_RED (void);
void LED_RED (void)
{
	GPIO_PORTF_DATA_R |=0x02;
}

int main()
{
	double x=0;
 if (x == 100.000)
 {
	 LED_RED ();
 }	
 return 0;
}



