#include <iostream>
#include "matrix.h"

int main()
{
	int size;
	std::cout << "Enter matrix size: "; std::cin >> size;

	int len;
	std::cout << "Enter length of matrix array: "; std::cin >> len;

	SquareMatrixArray matrix_arr(len, size);
	std::cout << "Generated matrices:\n";
	matrix_arr.show();
	int greatest = matrix_arr.find_greatest_diagonal_sum();

	std::cout << "The " << greatest + 1 << " matrix has the greatest diagonal sum:\n\n";
	matrix_arr.get_element(greatest).show();
	std::cout << "Sum: " << matrix_arr.get_element(greatest).sum_diagonal() << '\n';

	system("pause");
	return 0;
}