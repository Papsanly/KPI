#pragma once
#include "TMatrix.h"

class IntMatrix : public TMatrix<int> {
public:
    IntMatrix(int n, int m) {
        matrix = new int* [n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[m];
            for (int j = 0; j < m; j++) {
                matrix[i][j] = rand() % 10;
            }
        }
        this->n = n;
        this->m = m;
    }

	IntMatrix() {}
};