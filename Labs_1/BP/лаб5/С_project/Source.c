#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, S_div_max = 0, max_k = 1, S_div;
	printf("Enter value of n: ");
	scanf_s("%d", &n);
	printf("\n");

	for (int k = 1; k <= n; k++) {

		S_div = 0;

		for (int div = 1; div <= k; div++) {

			if (k % div == 0) S_div += div;

		}
		
		if (S_div > S_div_max) {

			max_k = k;
			S_div_max = S_div;

		}

		printf("k = %d: S_div = %d\n", k, S_div);

	}

	printf("\nThe value between 1 and n with maximum sum of divisors is: %d\n", max_k);
	printf("Its sum of divisors is: %d\n", S_div_max);

	return 0;

}