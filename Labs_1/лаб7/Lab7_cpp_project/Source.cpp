#include <stdio.h>
#include <iostream>
using namespace std;

void init_arr12(char[], char[]);
int init_arr3(char[], char[], char[]);
void browse(char[], int, int);
void solution(char[], int);

int main() {

	int len_arr3;
	char arr1[10], arr2[10], arr3[10];

	init_arr12(arr1, arr2);
	browse(arr1, 1, 10); browse(arr2, 2, 10);
	len_arr3 = init_arr3(arr1, arr2, arr3);
	browse(arr3, 3, len_arr3);
	solution(arr3, len_arr3);
	
	system("PAUSE>0");
	return 0;

}

void init_arr12(char arr1[], char arr2[]) {

	for (int i = 0; i < 10; i++) {
		arr1[i] = 2 * i + 22;
	}

	for (int i = 0; i < 10; i++) {
		arr2[i] = 48 - 2 * i;
	}

}

int init_arr3(char arr1[], char arr2[], char arr3[]) {
	
	int i_temp = 0;
	for (int i = 0; i < 10; i++) {
		
		int j = 0, is_in_arr2 = 0;
		while (j < 10 && !is_in_arr2) {
			
			if (arr1[i] == arr2[j]) {
			
				arr3[i_temp] = arr1[i];
				is_in_arr2 = 1;
				i_temp++;
			
			}
			j++;
	
		}
	
	}

	return i_temp;

}

void browse(char arr[], int n, int len) {

	cout << "Array " << n << ": [";
	for (int i = 0; i < len; i++) {
		printf("%2c", arr[i]);
	}
	cout << " ]" << endl;

}

void solution(char arr[], int len) {

	char min = arr[0], max = arr[0];
	for (int i = 1; i < len; i++) {

		if (arr[i] > arr[i - 1]) {
			max = arr[i];
		}

		if (arr[i] < arr[i - 1]) {
			min = arr[i];
		}

	}

	cout << "The min code is: " << min << " (" << int(min) << ")" << endl;
	cout << "The max code is: " << max << " (" << int(max) << ")" << endl;
	cout << "The sum of the min and max codes is: " << int(min) + int(max);

}