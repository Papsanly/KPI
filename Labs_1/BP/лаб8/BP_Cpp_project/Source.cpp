#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>

using namespace std;
 
int** init(int); 
void generate(int**, int); 
void incr(int*, int*, int, int, int*, int*); 
void output(int**, int); 
int find_min(int**, int); 
void del(int**, int); 

int main() {

	int size;
	int** matrix;
	cout << "Enter the size of the spiral matrix: "; cin >> size;

	matrix = init(size);
	generate(matrix, size);
	cout << "\nThe spiral matrix with size " << size << ":" << endl;
	output(matrix, size);
	cout << "The minimal angular elements of the matrix is " << find_min(matrix, size) << "\n\n";

	del(matrix, size);
	system("pause");
	return 0;

}

int** init(int size) { 

	int** matrix = new int* [size]; 
	for (int i = 0; i < size; i++) {
		*(matrix + i) = new int [size]; 
	}

	return matrix; 

}

void incr(int* i, int* j, int pos, int val, int* dir, int* scale) {
	
	bool UL = (*i == *scale && *j == *scale + 1);
	bool UR = (*i == pos - *scale && *j == *scale);
	bool DR = (*i == pos - *scale && *j == pos - *scale);
	bool DL = (*i == *scale && *j == pos - *scale);
	
	if (UR || DR || DL || UL) {
		*dir = (*dir + 1) % 4;
		if (UL) (*scale)++;
	}

	if (*dir == 0) (*i)++;
	else if (*dir == 1) (*j)++;
	else if (*dir == 2) (*i)--;
	else (*j)--;

}

void generate(int **matrix, int size) {

	int i = 0, j = 0, dir = 0, pos = size - 1, scale = 0;
	for (int val = 1; val <= size * size; val++) {
		*(*(matrix + i) + j) = val;
		incr(&i, &j, pos, val, &dir, &scale);
	}

}

void output(int **matrix, int size) {

	int width0 = floor(log(size * size) / log(10) + 1);
	int width1 = 1 + width0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		
		cout << "|";
		for (int j = 0; j < size; j++) {
			cout << setw(width1) << *(*(matrix + j) + i);
		}
		cout << setw(width0) << "|" << endl;
		
		if (i != size - 1) {
			int width_full = width1 * (size + 1) - 1;
			cout << "|" << setw(width_full) << "|" << endl;
		}
	
	}
	cout << endl;

}

int find_min(int** matrix, int size) {

	int UL = **matrix;
	int UR = **(matrix + size - 1);
	int DR = *(*(matrix + size - 1) + size - 1);
	int DL = *(*matrix + size - 1);

	if (UL < UR && UL < DR && UL < DL) return UL;
	else if (UR < UL && UR < DR && UR < DL) return UR;
	else if (DR < UL && DR < UR && DR < DL) return DR;
	else return DL;

}

void del(int **matrix, int size) {

 	for (int i = 0; i < size; i++) {
		delete[] *(matrix + i);
	}
	delete[] matrix;

}