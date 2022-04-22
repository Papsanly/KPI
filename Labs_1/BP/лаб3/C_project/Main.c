#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//defining factorial function
double fact(int n) { 
	return (n == 0) || (n == 1) ? 1 : n * fact(n - 1);
}

main() {

	double x, term = 1, index = 1, S = 0; //defining variables
	printf("Enter x (0 <= x <= 2): "); //prompting x value
	scanf_s("%lf", &x);

	if (x >= 0 && x <= 2) { //checking if x belongs to the domain

		while (fabs(term) >= 0.00001 || (x == 1 && index == 2)) { //checking for conditions
			
			term = (index * x * x - 1) / (1 + fact(pow(2, index - 1))); //evaluating terms
			S = S + term; //evaluating S as the sum of all terms
			index++; //incrementing index
			printf("%f\n", S); //printing S value

		}

	}

	else printf("The entered number does not belong to the domain"); //if x doesn't belong to the domain this message will show up

}