#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

int main()
{
	// Create file name variables
	std::string filename1 = "author_books.dat";
	std::string filename2 = "last_years_books.dat";

	// Get user input for mode
	int m;
	std::cout << "Enter mode: \n"
			"    Create new file - 0 \n"
			"    Append to existing file - 1 \n"
			"    View existing file - 2\n";
	std::cin >> m;
	mode M = mode(m);

	// Main program logic
	if (M != mode::view) {
		create_authors_file(filename1, M);
		selective_copy_authors_file(filename1, filename2);
	}
	out_authors_file(filename1, "Author's books:", 1);
	out_authors_file(filename2, "Author's books written in the last 4 years:", 1);
	out_authors_file(filename1, "Author's books written more than 5 years after writing", 0);

	system("pause");
}