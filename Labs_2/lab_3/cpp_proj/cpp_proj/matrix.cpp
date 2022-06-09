#include "matrix.h"
#include <windows.h>
#include <string>


SquareMatrix::SquareMatrix(int size) : size(size)
{
	for (int row = 0; row < size; row++) {
		std::vector<int> vec;
		for (int col = 0; col < size; col++)
			vec.push_back(rand() % 201 - 100);
		elements.push_back(vec);
	}
}


void SquareMatrix::show()
{
	for (std::vector<int> row : elements) {
		for (int element : row)
			std::cout << std::setw(5) << element;
		std::cout << '\n';
	}
	std::cout << '\n';
}


int SquareMatrix::sum_diagonal()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += elements[i][i];

	return sum;
}


SquareMatrixArray::SquareMatrixArray(int len, int size) : len(len), size(size)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
		matrices.push_back(SquareMatrix(size));
}


void SquareMatrixArray::show()
{
	int i = 1;
	for (SquareMatrix matrix : matrices) {
		std::cout << i++ << ")\n";
		matrix.show();
	}
	std::cout << "\n";
}


SquareMatrix SquareMatrixArray::get_element(int pos)
{
	return matrices[pos];
}


int SquareMatrixArray::find_greatest_diagonal_sum()
{
	int g_pos = 0;
	int g_val = matrices[0].sum_diagonal();
	int current;
	for (int i = 1; i < len; i++)
	{
		current = matrices[i].sum_diagonal();
		if (current > g_val) {
			g_pos = i;
			g_val = current;
		}
	}

	return g_pos;
}