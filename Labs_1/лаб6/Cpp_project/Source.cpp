#include <iostream>
using namespace std;

int n;
int max_S_div = 0, max_n = 1;

void input();
void solution(int n);
void output();
int Sum_divisors(int);

int main() {
	
	input();
	solution(n);
	output();

	system("pause>0");
	return 0;
}

void input() {
	cout << "Enter n: ";
	cin >> n;
}

void output() {
	cout << "The value between 1 and n with maximum sum of divisors is: " << max_n << endl;
	cout << "Its sum of divisors is: " << max_S_div;
}

int Sum_divisors(int k) {
	
	int S_div = 0;
	
	for (int div = 1; div <= k; div++) {
		if (k % div == 0) S_div += div;
	}

	return S_div;
}

void solution(int n) {

	if (n == 0) return;

	cout << "n = " << n << ": S_div = " << Sum_divisors(n) << endl;

	if (Sum_divisors(n) > max_S_div) {
		max_n = n;
		max_S_div = Sum_divisors(n);
	}

	solution(n - 1);

}