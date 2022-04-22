#include <stdlib.h>
#include <stdio.h>

main() {

	double x, y; //defining variables 
	printf("Enter the x coordinate: "); //prompting the x coordinate
	scanf_s("%lf", &x); //scaning for x
	printf("Enter the y coordinate: "); //prompting the y coordinate
	scanf_s("%lf", &y); //scaning for y
	
	if((x * x + y * y >= 9) && ((0 <= x && x <= 3 && -3 <= y && x <= 3) || (-3 <= x && x <= 0 && -3 <= y && y <= 0))) { //cheking for conditions

		printf("The point belongs to the shaded area"); //the point belongs to the shaded area if the above condition is true

	} else {

		printf("The point doesn't belong to the shaded area"); //the point doesn't belong to the shaded area if the above condition is false

	}

	return 0;

}