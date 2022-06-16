#pragma once
#include "TMatrix.h"

class IntMatrix : public TMatrix<int> {
public:
	IntMatrix(int n, int m) : TMatrix<int>(n, m) {}

    void fillMatrix() override {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                matrix[i][j] = rand() % 10; // NOLINT(cert-msc50-cpp)
    }

    IntMatrix() : TMatrix<int>() {}

};
