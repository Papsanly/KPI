#include <iostream>
#include <iomanip>
#include <string>

int find_del_ch(std::string&, char);
int** declr_mtx(int);
void get_ch_mtx(int**, std::string, int&);
void get_min_arr(int**, char*, int, int&, int&);
void get_max_arr(int**, char*, int, int&, int&);
void out_ch_mtx(int**, int);
void out_min_max(char*, char*, int, int, int, int);
void del_mtx(int**, int);
void sort_shell(int**, int);
void swap(int&, int&);

int main() {

	std::string str;
	std::cout << "Enter string: "; getline(std::cin, str);
	int min, max, ch_len, min_len, max_len, str_len = str.length();

	int** ch_mtx = declr_mtx(str_len);
	char* min_arr = new char [str_len];
	char* max_arr = new char [str_len];

	get_ch_mtx(ch_mtx, str, ch_len);
	sort_shell(ch_mtx, ch_len);
	out_ch_mtx(ch_mtx, ch_len);

	get_min_arr(ch_mtx, min_arr, ch_len, min_len, min);
	get_max_arr(ch_mtx, max_arr, ch_len, max_len, max);
	out_min_max(min_arr, max_arr, min, max, min_len, max_len);

	del_mtx(ch_mtx, str_len);
	delete[] min_arr;
	delete[] max_arr;
	
	system("pause");
	return 0;

}

int** declr_mtx(int len) {

	int** mtx = new int* [len];
	for (int i = 0; i < len; i++)
		*(mtx + i) = new int [2];

	return mtx;

}

void get_ch_mtx(int** ch_mtx, std::string str, int &len) {

	char ch, i;
	for (i = 0; !str.empty(); i++) {
		ch = str[0];
		ch_mtx[i][0] = int(ch);
		ch_mtx[i][1] = find_del_ch(str, ch);
	}
	len = i;

}

int find_del_ch(std::string &str, char ch) {

	int i = 0, frq = 0;
	while (i < str.length())
		if (str[i] == ch) {
			frq++;
			str.erase(i, 1);
		} else {
			i++;
		}

	return frq;

}

void out_ch_mtx(int** ch_mtx, int ch_len) {

	int width;

	std::cout << "\nCharacter frequency list:\n[";
	for (int i = 0; i < ch_len; i++)
		std::cout << "  " << ch_mtx[i][1] << "  ";
	std::cout << "]\n";

	std::cout << "[";
	for (int i = 0; i < ch_len; i++) {
		width = (int)log10(ch_mtx[i][1]) + 2;
		std::cout << std::setw(width) << "'" << char(ch_mtx[i][0]) << "' ";
	}
	std::cout << "]\n";

}

void get_min_arr(int** ch_mtx, char* min_arr, int ch_len, int &min_len, int &min) {

	min = ch_mtx[0][1];

	min_len = 0;
	for (int i = 0; i < ch_len; i++)
		if (ch_mtx[i][1] == min && !isspace(ch_mtx[i][0])) {
			min_arr[min_len] = char(ch_mtx[i][0]);
			min_len++;
		}

}

void get_max_arr(int** ch_mtx, char* max_arr, int ch_len, int &max_len, int &max) {

	max = ch_mtx[ch_len - 1][1];
	if (isspace(ch_mtx[ch_len - 1][0]))
		max = ch_mtx[ch_len - 2][1];

	max_len = 0;
	for (int i = 0; i < ch_len; i++)
		if (ch_mtx[i][1] == max && !isspace(ch_mtx[i][0])) {
			max_arr[max_len] = char(ch_mtx[i][0]);
			max_len++;
		}

}

void out_min_max(char* min_arr, char* max_arr, int min, int max, int min_len, int max_len) {

	std::cout << "\nThe character(s) with minimum amount of occurance (except of spaces) is ";
	for (int i = 0; i < min_len; i++)
		std::cout << "'" << min_arr[i] << "' ";
	std::cout << ": " << min << " time(s)\n";

	std::cout << "The character(s) with maximum amount of occurance (except of spaces) is ";
	for (int i = 0; i < max_len; i++)
		std::cout << "'" << max_arr[i] << "' ";
	std::cout << ": " << max << " time(s)\n\n";

}

void del_mtx(int** mtx, int len) {

	for (int i = 0; i < len; i++)
		delete[] *(mtx + i);
	delete[] mtx;

}

void sort_shell(int** mtx, int len) {

	for (int d = len / 2; d >= 1; d /= 2)
		for (int i = d; i < len; i++)
			for (int j = i; j >= d && mtx[j - d][1] > mtx[j][1]; j -= d) {
				swap(mtx[j][0], mtx[j - d][0]);
				swap(mtx[j][1], mtx[j - d][1]);
			}

}

void swap(int &a, int &b) {

	int c = a;
	a = b;
	b = c;

}