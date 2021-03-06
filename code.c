#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <math.h>
#define  radius_of_Earth  6371000 // in meters
#define pi  3.141591654 //pi = atan(1)* 4
void SystemInit(void);
void Init (void);
void LED_RED (void);
double distance_between_2_points ( double lat1 , double long1, double lat2 , double long2);
double degree_to_rad (double x);
void units_7segments_output (int x);
void tens_7segments_output (int x);
void Init (void)
{
SYSCTL_RCGCGPIO_R |= 0x23; //enable the clock for ports A,B,F
while ((SYSCTL_PRGPIO_R&0x23) == 0){} //To get an acknowledgement that the required ports has been activated.
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R |= 0x1E; // to control pins 1,2,3,4 in port F
GPIO_PORTF_DIR_R |= 0x0E; // output for pins 1,2,3 
GPIO_PORTF_DEN_R |= 0x1E; // ditgal for pins 1,2,3,4
GPIO_PORTF_AMSEL_R &= (~0x1E); // NO analog IO
GPIO_PORTF_AFSEL_R &=(~0x1E); // make it default for pins all pins (GPIO)
GPIO_PORTF_PCTL_R &= (~0xFFFF0); 
GPIO_PORTF_PUR_R|= 0x10; // connect internal resistance with pin 4 
GPIO_PORTF_DATA_R &= (~0x0E); // initialize the data = 0
GPIO_PORTA_LOCK_R = 0x4C4F434B;
GPIO_PORTA_CR_R |= 0x3C; // to control pins 2,3,4,5 in port A
GPIO_PORTA_DIR_R |= 0x3C; // all pins are outputs
GPIO_PORTA_DEN_R |= 0x3C; // all pins are digital
GPIO_PORTA_AMSEL_R &= (~0x3C); // No analog IO
GPIO_PORTA_AFSEL_R &= (~0x3C); // make it default for pins all pins (GPIO)
GPIO_PORTA_PCTL_R &= (~0x00FFFF00);
GPIO_PORTA_DATA_R &= (~0x3C); // initialize the data = 0
GPIO_PORTB_LOCK_R = 0x4C4F434B;
GPIO_PORTB_CR_R |= 0xFF; // to control all pins in port B
GPIO_PORTB_DIR_R |= 0xFF; // all pins are outputs
GPIO_PORTB_DEN_R |= 0xFF; // all pins are digital
GPIO_PORTB_AMSEL_R &= (~0xFF); // No analog IO
GPIO_PORTB_AFSEL_R &=(~0xFF); // make it default for pins all pins (GPIO)
GPIO_PORTB_PCTL_R &= (~0xFFFFFFFF);
GPIO_PORTB_DATA_R &= (~0xFF); // initialize the data = 0
}
// Pins B0->B3: units 7-segments outputs
// Pins B4->B7: tens 7-segments outputs
// Pins A4->A5: hundreds 7-segments outputs
// Pin A2: tens 7-segments enable
// Pin A3: hundreds 7-segments enable
void LED_RED (void) // turn on the red LED
{
	GPIO_PORTF_DATA_R |=0x02;
}
double degree_to_rad (double x) // Convert the angle from degree into radian
{
	x*= pi/180;
	return x;
}
double distance_between_2_points ( double lat1 , double long1, double lat2 , double long2)
{
	// Calculating the distance between 2 points given only their latitude and longitude
	// Based on formula obtained from great-circle distance
	// Vincenty formula
	// https://en.wikipedia.org/wiki/Great-circle_distance#Formulas (link from which we got the formula)
	lat1=degree_to_rad (lat1);
	long1=degree_to_rad (long1);
	lat2=degree_to_rad (lat2);
	long2=degree_to_rad (long2);
  double delta_long = long2-long1;
	double num1 = cos(lat2) * sin(delta_long);
	num1 = pow(num1,2);
	double num2 = ( cos(lat1) * sin(lat2) ) - ( sin(lat1) * cos(lat2) * cos(delta_long));
	num2= pow(num2,2);
	double num = num1+num2;
	num = sqrt (num);
	double den = ( sin(lat1) * sin(lat2) ) + ( cos(lat1) * cos(lat2) * cos(delta_long) );
	double delta = atan2(num,den);
	double dist = delta * radius_of_Earth ;
  return dist;	
}
void units_7segments_output (int x) //function to display the output on the units 7-segment display
{
	switch (x)
			{
				case 0 : GPIO_PORTB_DATA_R |= 0x00;
			break ;
				case 1 : GPIO_PORTB_DATA_R |= 0x01;
			break ;
				case 2 : GPIO_PORTB_DATA_R |= 0x02;
			break ;
				case 3 : GPIO_PORTB_DATA_R |= 0x03;
			break ;
				case 4 : GPIO_PORTB_DATA_R |= 0x04;
			break ;
				case 5 : GPIO_PORTB_DATA_R |= 0x05;
			break ;
				case 6 : GPIO_PORTB_DATA_R |= 0x06;
			break ;
				case 7 : GPIO_PORTB_DATA_R |= 0x07;
			break ;
				case 8 : GPIO_PORTB_DATA_R |= 0x08;
			break ;
				case 9 : GPIO_PORTB_DATA_R |= 0x09;
			break ;
			}
}
void tens_7segments_output (int x) //function to display the output on the tens 7-segment display
{
	switch (x) 
			{
				case 0 : GPIO_PORTB_DATA_R |= 0x00;
			break ;
				case 1 : GPIO_PORTB_DATA_R |= 0x10;
			break ;
				case 2 : GPIO_PORTB_DATA_R |= 0x20;
			break ;
				case 3 : GPIO_PORTB_DATA_R |= 0x30;
			break ;
				case 4 : GPIO_PORTB_DATA_R |= 0x40;
			break ;
				case 5 : GPIO_PORTB_DATA_R |= 0x50;
			break ;
				case 6 : GPIO_PORTB_DATA_R |= 0x60;
			break ;
				case 7 : GPIO_PORTB_DATA_R |= 0x70;
			break ;
				case 8 : GPIO_PORTB_DATA_R |= 0x80;
			break ;
				case 9 : GPIO_PORTB_DATA_R |= 0x90;
			break ;
			}
}	
int main()
{
	Init();
	int dist = 65; //dummy variable
	int units,tens,hundreds ; //We will divide each digit in a separate variables , ex: dist =127 , hundreds = 1 , tens = 2 , units = 7 
	if (dist >=0 && dist <= 9) // in this case we will use the units 7-segment only
		{
			GPIO_PORTA_DATA_R &= (~0x04); // tens 7 - segment enabler ==> 0 , tens 7-segments are off
			GPIO_PORTA_DATA_R &= (~0x08); // hundreds 7 - segment enabler ==> 0 , hundreds 7-segments are off
			units_7segments_output(dist);
		}
	else if (dist > 9 && dist <= 99 ) // in this case we will use the units & tens 7-segments , hundreds 7-segment will not be used
	{
		GPIO_PORTA_DATA_R &= (~0x08); // hundreds 7 - segment enabler ==> 0 , hundreds 7-segments are off
		units = dist % 10 ; // units = the value of units of dist
		units_7segments_output(units);
		tens = (dist-units)/10 ; // tens = the value of tens of dist
		GPIO_PORTA_DATA_R |= 0x04; // tens 7 - segment enabler
		tens_7segments_output(tens);
	}
	else if (dist > 99 && dist <= 999 )
	{
		int y = dist % 100 ; 
		units = y % 10; // units = the value of units of dist
		units_7segments_output(units);
		tens = (y-units)/10 ; // tens = the value of tens of dist
		GPIO_PORTA_DATA_R |= 0x04; // tens 7 - segment enabler
		tens_7segments_output(tens);
		hundreds = (dist-tens)/100 ;
		GPIO_PORTA_DATA_R |= 0x08; // hundreds 7 - segment enabler
		// Complete code without decoder to get the number on 7* segment, but we will only use no 1 as we will apply the condition (dist <=199) , so we only need b&c led to form 1
		/*switch (hundreds)
		{
				case 0 : GPIO_PORTB_DATA_R |= 0x3F;
			break ;
				case 1 : GPIO_PORTB_DATA_R |= 0x06;
			break ;
				case 2 : GPIO_PORTB_DATA_R |= 0x5B;
			break ;
				case 3 : GPIO_PORTB_DATA_R |= 0x4F;
			break ;
				case 4 : GPIO_PORTB_DATA_R |= 0x66;
			break ;
				case 5 : GPIO_PORTB_DATA_R |= 0x6D;
			break ;
				case 6 : GPIO_PORTB_DATA_R |= 0x7D;
			break ;
				case 7 : GPIO_PORTB_DATA_R |= 0x07;
			break ;
				case 8 : GPIO_PORTB_DATA_R |= 0x7F;
			break ;
				case 9 : GPIO_PORTB_DATA_R |= 0x6F;
			break ;
		}*/
		GPIO_PORTA_DATA_R |= 0x30; // pins A4 & A5 is pin b&c on the 7-segment (form number 1)
		LED_RED();
	}
	return 0 ;
}