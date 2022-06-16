from abc import abstractmethod


class Matrix:

    def __init__(self, n, m):
        self.matrix = []
        self.m = n
        self.n = m

    @abstractmethod
    def fill(self):
        pass

    def get_average(self):
        counter = 0
        for i in range(self.n):
            for j in range(self.m):
                counter += self.matrix[i][j]
        return counter / (self.n * self.m)

    def print(self):
        for i in range(self.n):
            for j in range(self.m):
                print('{0: >5}'.format(f'{round(self.matrix[i][j], 1)}'), end='\t')
            print()

    def increase(self, value):
        for i in range(self.n):
            for j in range(self.m):
                self.matrix[i][j] += value

    def decrease(self, value):
        for i in range(self.n):
            for j in range(self.m):
                self.matrix[i][j] -= value
