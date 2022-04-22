#include <stdlib.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>


int main() {

	double B_deg;
	printf("Enter the angle to convert in degrees\n");
	scanf_s("%lf", &B_deg);
	double B_rad = B_deg * M_PI / 180;
	printf("This angle in radians is %f\n", B_rad);

	return 0;
}