#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;

void create_authors_file(string& filename, mode M)
{
	// Open authors file
	ofstream books_file;
	bool mode;

	if (M == mode::create)
		books_file.open(filename, std::ios::binary);
	else
		books_file.open(filename, std::ios::binary | std::ios::app);

	if (!books_file) {
		cout << "Cannot open file " << filename << '\n';
		system("pause");
		exit(1);
	}

	// Getting user input for authors attributes
	AuthorBooks book;
	string book_name;
	char active = 'y';
	while (active == 'y') {
		cin.ignore();
		cout << "\nEnter book name: "; getline(cin, book_name);
		strcpy_s(book.name, book_name.c_str());
		cout << "Enter year of writing: "; cin >> book.write_year;
		cout << "Enter year of publishing (not published - 0): "; cin >> book.publish_year;

		books_file.write((char*)&book, sizeof(AuthorBooks));

		cout << "Continue? (y/n) "; cin >> active;
	}

	books_file.close();
}

void selective_copy_authors_file(string& filename, string& copy_filename)
{
	// Open input authors file
	ifstream books_file(filename, std::ios::binary);
	if (!books_file) {
		cout << "Cannot open file " << filename << '\n';
		system("pause");
		exit(1);
	}

	// Open output authors file
	ofstream last_years_books_file(copy_filename, std::ios::binary);
	if (!books_file) {
		cout << "Cannot open file " << copy_filename << '\n';
		system("pause");
		exit(1);
	}

	// Copying book objects to output file
	AuthorBooks book;
	while (books_file.read((char*)&book, sizeof(AuthorBooks)))
		if (2022 - book.write_year <= 4)
			last_years_books_file.write((char*)&book, sizeof(AuthorBooks));

	books_file.close();
	last_years_books_file.close();
}

void out_authors_file(string& filename, string message, bool full_out)
{
	ifstream file(filename, std::ios::binary);
	if (!file) {
		cout << "Cannot open file" << filename << '\n';
		system("pause");
		exit(1);
	}

	cout << '\n' + message + '\n';
	cout << "---------------------------------\n";

	int count = 0;
	AuthorBooks book;
	while (file.read((char*)&book, sizeof(AuthorBooks))) {
		int diff = book.publish_year - book.write_year;
		if (full_out || diff >= 5) {
			cout << "Book name: " << book.name << '\n';
			cout << "     year of writing: " << book.write_year << '\n';
			cout << "     year of publishing: " << book.publish_year << "\n\n";
			count++;
		}
	}
	if (!count)
		cout << "[Empty]\n";

	file.close();

	cout << "---------------------------------\n";
}