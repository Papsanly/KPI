#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double** declr_mtx(int, int);
double rand_double(int, int, int);
void gen_mtx(double**, int, int, int, int, int);
void swap_null_in_mtx(double**, int, int);
int find_null(double**, int, int);
void swap(double&, double&);
void out_mtx(double**, int, int, int, int, int);

int main() {

	int size_x, size_y, rng_start, rng_end, precision;
	cout << "Enter matrix size (m by n): "; cin >> size_y >> size_x;
	cout << "Enter range (from - to) [|range|<=16383]: "; cin >> rng_start >> rng_end;
	cout << "Enter precision: [<=4]: "; cin >> precision;

	srand((unsigned int)time(NULL));

	double** matrix = declr_mtx(size_x, size_y);
	gen_mtx(matrix, size_x, size_y, rng_start, rng_end, precision);
	
	cout << "\nGenerated matrix:\n";
	out_mtx(matrix, size_x, size_y, rng_start, rng_end, precision);
	
	swap_null_in_mtx(matrix, size_x, size_y);
	
	cout << "\nMatrix after swapping:\n";
	out_mtx(matrix, size_x, size_y, rng_start, rng_end, precision);

	system("pause");
	return 0;

}

double** declr_mtx(int size_x, int size_y) {

	double** matrix = new double* [size_x];
	for (int i = 0; i < size_x; i++)
		*(matrix + i) = new double [size_y];

	return matrix;

}

void gen_mtx(double** matrix, int size_x, int size_y, int rng_start, int rng_end, int precision) {

	for (int j = 0; j < size_y; j++)
		for (int i = 0; i < size_x; i++)
			*(*(matrix + i) + j) = rand_double(rng_start, rng_end, precision);

}

double rand_double(int rng_start, int rng_end, int precision) {

	double random;
	int rand_int, rand_frac;
	int y = -rng_start;
	int x = rng_end + y;

	rand_int = rand() % x - y;
	rand_frac = rand() % int(pow(10, precision));
	random = rand_int + rand_frac * pow(0.1, precision);

	return random;

}

void swap_null_in_mtx(double** matrix, int size_x, int size_y) {

	int col;
	for (int row = 0; row < size_x; row++) {
	
		col = find_null(matrix, size_x, row);
		if (col != -1) {
			swap(*(*(matrix + col) + row), *(*(matrix + size_y - 1) + row));
			cout << "Row " << row + 1 << " contains a zero at column " << col + 1 << "\n";
		} else 
			cout << "Row " << row + 1 << " does not contain a zero\n";
	
	}

}

int find_null(double** matrix, int size_x, int row) {

	for (int col = 0; col < size_x; col++)
		if (*(*(matrix + col) + row) == 0)
			return col;

	return -1;

}

void swap(double &a, double &b) {

	double c = a;
	a = b;
	b = c;

}

void out_mtx(double** matrix, int size_x, int size_y, int rng_start, int rng_end, int precision) {

	int range;
	if (fabs(rng_start) < fabs(rng_end))
		range = fabs(rng_end);
	else
		range = fabs(rng_start);

	int width = (int)log10(range) + precision + 4;
	int width_full = width * size_x + 3;

	cout << "\n";
	for (int j = 0; j < size_y; j++) {

		cout << "|";

		for (int i = 0; i < size_x; i++)
			cout << setw(width) << setprecision(precision) << fixed
			<< *(*(matrix + i) + j);

		cout << " |\n";

		if (j != size_y - 1)
			cout << "|"
			<< setw(width_full)
			<< "|\n";

	}
	cout << "\n";

}