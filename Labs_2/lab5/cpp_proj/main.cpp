#include "IntMatrix.h"
#include "FloatMatrix.h"

int main() {
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)

	const int SIZE = 5;
	const int ROWS = 4;
	const int COLS = 4;
	const int DECREASE_VALUE = 5;
	const int INCREASE_VALUE = 9;

	IntMatrix ints[SIZE];
	FloatMatrix floats[SIZE];
    cout << "Matrices:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << "\n" << i + 1 << " (int):\n";
        ints[i] = IntMatrix(ROWS, COLS);
        ints[i].fillMatrix();
        ints[i].increase(INCREASE_VALUE);
        ints[i].print();

        cout << "\n" << i + 1<< " (float):\n";
		floats[i] = FloatMatrix(ROWS, COLS);
        floats[i].fillMatrix();
        floats[i].decrease(DECREASE_VALUE);
        floats[i].print();
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

	cout << "\nMin value: " << minAverage << ". Matrix (" << indexMin + 1 << "):\n";
	if (isMinInt)
		ints[indexMin].print();
	else
		floats[indexMin].print();

}