#include <ctime>

#include "matrix_3x3.h"


int main()
{
	srand((unsigned int)time(NULL));

	// Get all Matrix3x3 static attributes
	const int SIZE = Matrix3x3::SIZE;
	const int MIN = Matrix3x3::MIN;
	const int MAX = Matrix3x3::MAX;

	std::cout << "<======================================================================================>\n";
	
	// Default constructor 
	std::cout << "<Matrix M1: Initialization by filling matrix with random values in range [" 
			  << MIN << ", " << MAX << "]>\n\n";
	Matrix3x3 M1;
	M1.show("Default constructor matrix M1:\n");

	std::cout << "<-------------------------------------------------------------------------->\n";
	
	// Parametric constructor
	int vec[SIZE * SIZE];
	std::cout << "<Matrix M2: Initialization by filling matrix with a vector>\n\n"
			  << "Enter initialization vector (format: [v1] [v2] [v3] ... [v" << SIZE * SIZE << "])\n";
	for (int i = 0; i < SIZE * SIZE; i++)
		std::cin >> vec[i];
	Matrix3x3 M2(vec);
	M2.show("Parametric constructor matrix M2:\n");

	std::cout << "<-------------------------------------------------------------------------->\n";
	
	// Copy constructor
	std::cout << "<Matrix M3: Initialization by copying another matrix>\n\n";
	Matrix3x3 M3 = M2;
	M3.show("Copy constructor matrix M3 = M2:\n");

	std::cout << "<======================================================================================>\n";

	// Using operator* overloading
	M3 = M1 * M2;
	M3.show("Matrix M3 after multiplication with M1 and M2 using operator* overloading:\n");

	std::cout << "<-------------------------------------------------------------------------->\n";
	
	// Using operator++ overloading
	M3++.show("Matrix M3 after incrementation using operator++ overloading:\n");

	std::cout << "<-------------------------------------------------------------------------->\n";
	
	// Finding determinate with class method if possible
	int det = M3.determinant_3x3();
	std::cout << "Determinate of matrix M3: " << det << "\n\n";
	
	std::cout << "<======================================================================================>\n";
	
	system("pause");
	return 0;
}