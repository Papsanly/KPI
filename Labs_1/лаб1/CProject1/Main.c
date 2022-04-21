#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
	
	double a;
	double b;
	double c;
	printf("Enter the distance to the country house\n");
	scanf_s("%lf", &a);
	printf("Enter the amount of gasoline consumed by the car per 100 km\n");
	scanf_s("%lf", &b);
	printf("Enter the price of one liter of gasoline\n");
	scanf_s("%lf", &c);
	double S = 2 * a * b * c / 100;
	printf("The cost of a trip by car to the country house(back and forth) is %f\n", S);

	return 0;
}