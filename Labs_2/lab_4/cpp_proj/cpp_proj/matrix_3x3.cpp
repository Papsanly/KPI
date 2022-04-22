#include "matrix_3x3.h"


Matrix3x3::Matrix3x3()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			elements[i][j] = rand() % (MAX - MIN + 1) + MIN;
}


Matrix3x3::Matrix3x3(int vec[])
{
	int val = 0;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			elements[i][j] = vec[val++];
}


Matrix3x3::Matrix3x3(const Matrix3x3& other)
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			elements[i][j] = other.elements[i][j];
}


Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other)
{
	Matrix3x3 result;
	int result_value;
	for (int row = 0; row < SIZE; row++)
		for (int col = 0; col < SIZE; col++) 
		{
			result_value = 0;
			for (int k = 0; k < SIZE; k++)
				result_value += elements[row][k] * other.elements[k][col];

			result.elements[row][col] = result_value;
		}
	return result;
}


Matrix3x3& Matrix3x3::operator++(int notused)
{
	for (int row = 0; row < SIZE; row++)
		for (int col = 0; col < SIZE; col++)
			elements[row][col]++;
	return *this;
}


void Matrix3x3::show(std::string message)
{
	unsigned int width_min = std::to_string(MIN).length();
	unsigned int width_max = std::to_string(MAX).length();
	unsigned int width = (width_min > width_max) ? width_min + 1 : width_max + 1;

	std::cout << message << std::endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			std::cout << std::setw(width) << elements[i][j];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int Matrix3x3::determinate_3x3()
{
	if (SIZE == 3) {
		int det = 0;
		int term;
		for (int col = 0; col < 3; col++) {
			term = elements[0][col] * determinate_2x2(0, col);
			if (col % 2)
				det -= term;
			else
				det += term;
		}
		return det;
	}
	else
		std::cout << "Cannot find 3x3 determinate, SIZE != 3" << "\n\n";
}


int Matrix3x3::determinate_2x2(int crossed_row, int crossed_col)
{
	int minor[2][2];

	int minor_row = 0, minor_col;
	for (int row = 0; row < 3; row++) {
		minor_col = 0;
		if (row != crossed_row) {
			for (int col = 0; col < 3; col++) {
				if (col != crossed_col) {
					minor[minor_row][minor_col] = elements[row][col];
					minor_col++;
				}
			}
			minor_row++;
		}
	}
	return minor[0][0] * minor[1][1] - minor[0][1] * minor[1][0];
}