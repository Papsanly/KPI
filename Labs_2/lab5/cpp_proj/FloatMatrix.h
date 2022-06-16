#pragma once
#include "TMatrix.h"

class FloatMatrix : public TMatrix<float> {
public:
    FloatMatrix(int n, int m) : TMatrix<float>(n, m) {}

    void fillMatrix() override {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                matrix[i][j] = float(rand() % 10) + float(rand() % 10) / 10; // NOLINT(cert-msc50-cpp)
    }

    FloatMatrix() : TMatrix<float>() {}

};
