import random

from matrix import Matrix


class IntMatrix(Matrix):

    def fill(self):
        self.matrix = [[random.randint(0, 10) for _ in range(self.m)]
                       for _ in range(self.n)]
        