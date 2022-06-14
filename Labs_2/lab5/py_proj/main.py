from int_matrix import IntMatrix
from float_matrix import FloatMatrix


def main():
    size = 5
    rows = 4
    cols = 4
    decrease_value = 5
    increase_value = 9

    ints = [IntMatrix(rows, cols) for _ in range(size)]
    floats = [FloatMatrix(rows, cols) for _ in range(size)]

    for int_m, float_m in zip(ints, floats):
        int_m.increase(increase_value)
        float_m.decrease(decrease_value)

    min_avrg = rows * cols * 10
    min_idx = 0
    isminint = False

    for i, (int_m, float_m) in enumerate(zip(ints, floats)):
        if int_m.get_average() < min_avrg:
            min_avrg = int_m.get_average()
            isminint = True
            min_idx = i

        if float_m.get_average() < min_avrg:
            min_avrg = float_m.get_average()
            isminint = False
            min_idx = i

    print(f'Min value: {round(min_avrg, 3)}, matrix:')

    if isminint:
        ints[min_idx].print()
    else:
        floats[min_idx].print()


if __name__ == '__main__':
    main()
