#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int A = 0, B = INT_MAX;
string str1 = "Enter the observation time: ";
string str2 = "Enter the height of the tree: ";
string str3 = "Enter the distance between the snail and the ground at the beginning of the observation: ";

int input_check(string); //�������� �� �������� �����
void init(int*, int*); //��������� ������ �� �������� �����
void browse(int*, int*); //��������� �����
void go_up(); //���������� ������� �� 2 �� ����� ���� �������
void go_down(); //���������� ������� �� 1 �� ���� ���� �������

int main() {

	int n = input_check(str1);
	int* M = new int [n];

	init(M, &n);
	browse(M, &n);

	for (int i = 0; i < n; i++) (*(M + i) == 1) ? go_up() : go_down();
	cout << "The distance between the snail and the ground at the end of the observation: " << A;

	system("PAUSE>0");

}

int input_check(string message) {

	int variable;
	cout << message; cin >> variable;

	while (variable < 0 || variable > B) {

		cout << "Invalid input! Try again" << endl;
		cout << message; cin >> variable;
		
	}

	return variable;

}

void init(int *arr, int *len) {

	B = input_check(str2); //������ ������
	A = input_check(str3); //������� �� ������� �� ���� �� �������

	srand(time(NULL));
	for (int i = 0; i < *len; i++) *(arr + i) = rand() % 2;

}

void browse(int *arr, int *len) {
	
	cout << endl << "Output: (1 - Sunny day, 0 - Cloudy day) " << endl << "Weather: ";
	for (int i = 0; i < *len; i++) cout << *(arr + i) << ' ';
	cout << endl;

}

void go_up() {

	if (A < B) {
		(A != B - 1) ? A += 2 : A += 1;
	}

}

void go_down() {

	if (A > 0) A -= 1; 

}