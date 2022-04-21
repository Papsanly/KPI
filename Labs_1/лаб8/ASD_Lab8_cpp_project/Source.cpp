#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;

double** declr_mtx(int, int);
double* declr_arr(int);
double rand_double(int, int);
void gen_mtx(double**, int, int, int, int);
void get_arr(double**, double*, int, int);
void out_mtx(double**, int, int, int, int);
void out_arr(double*, int, int, int);
void swap(double*, double*);
void sort_shell(double*, int);


int main() {

    int size_x = 8, size_y = 4;
    double** matrix = declr_mtx(size_x, size_y);
    double* array = declr_arr(size_x);
    int range, precision;

    cout << "Enter range (<=16383): "; cin >> range;
    cout << "Enter number of significant figures after decimal point (<=4): "; cin >> precision;

    srand((unsigned int)time(NULL));
   
    gen_mtx(matrix, size_x, size_y, range, precision);
    get_arr(matrix, array, size_x, size_y);
   
    cout << "\nGenerated matrix is: \n";
    out_mtx(matrix, size_x, size_y, range, precision);

    cout << "Resulting array is: \n";
    out_arr(array, size_x, range, precision);

    sort_shell(array, size_x);
    cout << "Resulting sorted array is: \n";
    out_arr(array, size_x, range, precision);

    system("pause");
    return 0;

}


double** declr_mtx(int size_x, int size_y) {

    double** matrix = new double* [size_x];
    for (int i = 0; i < size_x; i++) {
        *(matrix + i) = new double [size_y];
    }

    return matrix;

}

double* declr_arr(int size_x) {

    double* array = new double[size_x];
    return array;

}

double rand_double(int range, int precision) {

    double random;
    int rand_int, rand_frac;
    rand_int = rand() % (2 * range) - range;
    rand_frac = rand() % int(pow(10, precision));
    random = rand_int + rand_frac * pow(0.1, precision);

    return random;

}

void gen_mtx(double** matrix, int size_x, int size_y, int range, int precision) {

    for (int j = 0; j < size_y; j++)
        for (int i = 0; i < size_x; i++)
            *(*(matrix + i) + j) = rand_double(range, precision);

}

void get_arr(double** matrix, double* array, int size_x, int size_y) {

    for (int i = 0; i < size_x; i++) {
        *(array + i) = 1;
        for (int j = 0; j < size_y; j++)
            *(array + i) *= *(*(matrix + i) + j);
    }

}

void out_mtx(double** matrix, int size_x, int size_y, int range, int precision) {

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

void out_arr(double* array, int size_x, int range, int precision) {

    cout << "\n[  ";
    for (int i = 0; i < size_x; i++)
        cout << setprecision((long long)4 * precision) 
             << *(array + i) << "  ";
    cout << "]\n\n";

}

void swap(double* a, double* b) {

    double c = *a;
    *a = *b;
    *b = c;

}

void sort_shell(double* array, int size) {

    for (int d = size / 2; d >= 1; d /= 2)
        for (int i = d; i < size; i++)
            for (int j = i; j >= d && array[j - d] > array[j]; j -= d)
                swap(array + j, array + j - d);

}