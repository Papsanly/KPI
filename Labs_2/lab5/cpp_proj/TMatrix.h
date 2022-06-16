#pragma once
#include <iostream>
#include <iomanip>

using std::cout;

template <typename T>
class TMatrix {

public:

    TMatrix() = default;

    TMatrix(int n, int m): n(n), m(m) {
        matrix = new T* [n];
        for (int i = 0; i < n; i++)
            matrix[i] = new T [m];
    }

    virtual void fillMatrix() {};

	T getAverage() {
		T counter = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				counter += matrix[i][j];
		return counter / (n * m);
	}

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << std::setw(5) << std::setprecision(2) << matrix[i][j];
			cout << "\n";
		}
	}

	void increase(T value) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				matrix[i][j] += value;
	}

	void decrease(T value) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				matrix[i][j] -= value;
	}

protected:

    T **matrix;
    int n{};
    int m{};

};
