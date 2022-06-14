import math
import random

from matrix import Matrix


class FloatMatrix(Matrix):

    def __init__(self, n, m):
        super().__init__(n, m)
        self.matrix = [[round(10 * random.random(), 1) for _ in range(self.m)]
                       for _ in range(self.n)]
