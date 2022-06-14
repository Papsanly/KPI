#include "IntMatrix.h"
#include "FloatMatrix.h"

int main() {
    srand(time(nullptr));

	const int SIZE = 5;
	const int ROWS = 4;
	const int COLS = 4;
	const int DECREASE_VALUE = 5;
	const int INCREASE_VALUE = 9;

	IntMatrix ints[SIZE];
	FloatMatrix floats[SIZE];
	for (int i = 0; i < SIZE; i++) {
		ints[i] = IntMatrix(ROWS, COLS);
		floats[i] = FloatMatrix(ROWS, COLS);
	}

	for (int i = 0; i < SIZE; i++) {
		ints[i].increase(INCREASE_VALUE);
		floats[i].decrease(DECREASE_VALUE);
	}

	double minAverage = ROWS * COLS * 10;
	int indexMin = 0;
	bool isMinInt = false;

	for (int i = 0; i < SIZE; i++) {
		if (ints[i].getAverage() < minAverage) {
			minAverage = ints[i].getAverage();
			isMinInt = true;
			indexMin = i;
		}

		if (floats[i].getAverage() < minAverage) {
			minAverage = floats[i].getAverage();
			isMinInt = false;
			indexMin = i;
		}
	}
	cout << "Min value: " << minAverage << ", matrix:\n";

	if (isMinInt) {
		ints[indexMin].print();
	}
	else {
		floats[indexMin].print();
	}

}