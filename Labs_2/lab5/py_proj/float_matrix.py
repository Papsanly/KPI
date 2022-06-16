import random

from matrix import Matrix


class FloatMatrix(Matrix):

    def fill(self):
        self.matrix = [[round(10 * random.random(), 1) for _ in range(self.m)]
                       for _ in range(self.n)]
