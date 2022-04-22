#include <stdlib.h>
#include <stdio.h>

main() {

	//setting the variables
	double q, r, b, c, d; 
	int n;
	printf("Enter q: ");
	scanf_s("%lf", &q);
	printf("Enter r: ");
	scanf_s("%lf", &r);
	printf("Enter b: ");
	scanf_s("%lf", &b);
	printf("Enter c: ");
	scanf_s("%lf", &c);
	printf("Enter d: ");
	scanf_s("%lf", &d);
	printf("Enter n: ");
	scanf_s("%d", &n); // number of iterations
	double x_0 = c, x_1 = d, x_2, x_3;

	for (int k = 2; k <= n; k++) { // arithmetic cycle

		x_2 = q * x_1 + r * x_0 + b; // x_n calculation
		printf("\nx_%d = %f", k, x_2); // printing intermediate values
		x_0 = x_1; //shifting the variables 
		x_1 = x_2;

	}

	printf("\n\nThe final x_%d value: %f\n", n, x_1); // printing the final value

	return 0;

}
