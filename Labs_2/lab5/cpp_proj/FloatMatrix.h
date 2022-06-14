#pragma once
#include "TMatrix.h"

class FloatMatrix : public TMatrix<float> {
public:
	FloatMatrix(int n, int m) {
        matrix = new float * [n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new float [m];
            for (int j = 0; j < m; j++) {
                matrix[i][j] = (float)(rand() % 10) + (float)(rand() % 10) / 10;
            }
        }
        this->n = n;
        this->m = m;
    }

    FloatMatrix() {}
};
