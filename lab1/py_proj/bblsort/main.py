from random import shuffle
from time import time

def create_array(size):
	arr = list(range(1, size + 1))
	#shuffle(arr)
	return arr[::-1]

def bubble_sort(arr):
	size = len(arr)
	comps = 0
	swaps = 0
	is_sorted = False

	while not is_sorted:
		i = 0
		is_sorted = True
		for i in range(size - i - 1):
			comps += 1
			if arr[i] > arr[i + 1]:
				swaps += 1
				arr[i], arr[i + 1] = arr[i + 1], arr[i]
				is_sorted = False
		i += 1

	return comps, swaps

def comb_sort(arr):
	size = len(arr)
	is_sorted = False
	gap = size
	ratio = 1.24733
	comps = 0
	swaps = 0

	while not is_sorted and gap > 1:
		gap = int(gap / ratio) if gap >= 1 else 1
		for i in range(size - gap):
			comps += 1
			if arr[i] > arr[i + gap]:
				swaps += 1
				arr[i], arr[i + gap] = arr[i + gap], arr[i]
				is_sorted = False

	return comps, swaps

def out_array(arr):
	for i, item in enumerate(arr):
		if (i + 1) % 20:
			print('{0:>8}'.format(str(item)), end = '')
		else:
			print('{0:>8}'.format(str(item)))
	print()


def main():
	size = 500000
	
	arr = create_array(size)
	print('Unsorted array:')
	out_array(arr)

	t_start = time()
	comps, swaps = comb_sort(arr)
	t = time() - t_start
	print('\nSorted array:')
	out_array(arr)

	print(f'\nNumber of comparings: {comps}')
	print(f'Number of swaps: {swaps}')
	print(f'Sorting time: {t} seconds\n')

if __name__ == '__main__':
	main()