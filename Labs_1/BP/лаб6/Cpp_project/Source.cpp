#include <iostream>
using namespace std;

void init(int *);
void browse(int *, int *);
int Sum_divisors(int k);

int main() {

	int n;
	int num1, num2;

	init(&n);

	for (num1 = 1; num1 <= n; num1++) {
		for (num2 = num1; num2 <= n; num2++) {
			if ((Sum_divisors(num1) == num2) && (Sum_divisors(num2) == num1)) {
				
				browse(&num1, &num2);
			
			}
		}
	}

	system("pause>0");

}

void init(int *n) {

	cout << "Enter the value of n: ";
	cin >> *n;

}

void browse(int *num1, int *num2) {

	cout << "Numbers " << *num1 << " and " << *num2 << " are friendly" << endl;

}

int Sum_divisors(int k) {

	int S_div = 0;

	for (int div = 1; div <= k / 2; div++) {
		if (k % div == 0) S_div += div;
	}

	return S_div;

}