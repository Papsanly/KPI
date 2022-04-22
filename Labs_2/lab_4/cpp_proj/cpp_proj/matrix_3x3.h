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

	int determinate_2x2(int row, int col);

public:

	// Constructors
	Matrix3x3(); // Default
	Matrix3x3(int vec[]); // Parametric
	Matrix3x3(const Matrix3x3& other); // Copy
	
	// Operator* overloading for matrix multiplication
	Matrix3x3 operator*(const Matrix3x3& other);

	// Operator++ overloading for incrementing all matrix elements
	Matrix3x3& operator++(int notused);

	// Find matrix determinate
	int determinate_3x3();

	// Output matrix elements to screen
	void show(std::string message);
};
