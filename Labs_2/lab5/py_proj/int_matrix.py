import random

from matrix import Matrix


class IntMatrix(Matrix):

    def __init__(self, n, m):
        super().__init__(n, m)
        self.matrix = [[random.randint(0, 10) for _ in range(self.m)]
                       for _ in range(self.n)]
        