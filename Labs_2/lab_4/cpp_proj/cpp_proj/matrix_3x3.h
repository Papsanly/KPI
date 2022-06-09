#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Matrix3x3
{
public:

	// Matrix size
	static const int SIZE = 3;

	// Matrix element min value
	static const int MIN = 0;

	// Matrix element max value
	static const int MAX = 1000;

private:

	int elements[SIZE][SIZE];

protected:

	int determinant_2x2(int row, int col);

public:

	// Element getter
	int get_element(int row, int col);

	// Constructors
	Matrix3x3(); // Default
	Matrix3x3(int vec[]); // Parametric
	Matrix3x3(const Matrix3x3& other); // Copy
	
	// Operator* overloading for matrix multiplication
	Matrix3x3 operator*(const Matrix3x3& other);

	// Operator++ overloading for incrementing all matrix elements
	Matrix3x3 operator++(int not_used);

	// Find matrix determinate
	int determinant_3x3();

	// Output matrix elements to screen
	void show (std::string message) const;
};
