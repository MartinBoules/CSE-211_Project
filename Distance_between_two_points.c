#include "tm4c123gh6pm.h"
#include <math.h>
#define  radius_of_Earth  6371000
#define pi  3.141591654 

double distance_between_2_points ( double lat1 , double long1, double lat2 , double long2);
double degree_to_rad (double x);
double degree_to_rad (double x)
{
	x*= pi/180;
	return x;
}
double distance_between_2_points ( double lat1 , double long1, double lat2 , double long2)
{
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




