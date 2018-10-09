#include <stdio.h> 
#include <math.h>
#define PI 3.1415926

int main (void) {
	double area, side, radius, areac;
	scanf ("%lf",&area);
	side = sqrt(area);
	radius = sqrt(area/PI);
	areac = (sqrt(2) * side / 2)*(sqrt(2) * side / 2)*PI;
	printf ("%.3lf %.3lf %.3lf\n",side,radius,areac);
	return 0;
}