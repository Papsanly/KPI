#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>


class SquareMatrix
{
private:
	
	int size;
	std::vector<std::vector<int>> elements;

public:

	SquareMatrix(int size);
	void show();
	int sum_diagonal();
};


class SquareMatrixArray
{
private:
	
	int len, size;
	std::vector<SquareMatrix> matrices;

public:

	SquareMatrixArray(int len, int size);
	void show();
	SquareMatrix get_element(int pos);
	int find_greatest_diagonal_sum();
};
