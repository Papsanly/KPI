#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "header.h"

using std::cout;
using std::cin;
using std::string;
using std::ofstream;
using std::ifstream;

void write_to_file(string& filename)
{
	// Open file
	ofstream out_file;
	bool mode;
	
	cout << "Enter mode (create new file - 0, append to existing file - 1): "; cin >> mode;
	
	if (mode)
		out_file.open(filename, std::ios::app);
	else
		out_file.open(filename);
	
	if (!out_file) {
		cout << "Cannot open file " << filename << '\n';
		system("pause");
		exit(1);
	}

	// Get user input
	cout << "\nEnter text\nEnd with CTRL+S\n\n";

	string text;
	cin.ignore();
	getline(cin, text, (char)19);
	out_file << text;
	if (text.back() != '\n')
		out_file << '\n';

	// Close the file
	out_file.close();
}

void manipulate_file(string& in_filename, string& out_filename)
{
	// Open input file
	ofstream out_file(out_filename);
	if (!out_file) {
		cout << "Cannot open file " << out_filename << '\n';
		system("pause");
		exit(1);
	}

	// Open output file
	ifstream in_file(in_filename);
	if (!in_file) {
		cout << "Cannot open file " << in_filename << '\n';
		system("pause");
		exit(1);
	}

	// Write manipulated lines to output file from input file line by line
	string line;
	while (getline(in_file, line))
		out_file << manipulate(line) + '\n';

	// Close files
	in_file.close();
	out_file.close();
}

string manipulate(string line)
{
	string new_line;
	std::vector<string> words = split(line);
	size_t count = 0;

	// Delete first and last space characters and double in-between ones
	for (size_t i = 0; i < words.size(); i++) {
		if (i == 0 || i >= words.size() - 2)
			new_line += words[i];
		else {
			new_line += words[i] + "  ";
			count++;
		}
	}

	return new_line + " [" + std::to_string(count) + "]";
}

std::vector<string> split(string line)
{
	std::vector<string> words;
	size_t space;
	string word;

	// Splite words based on space position
	while (!line.empty()) {
		space = line.find(' ');
		word = line.substr(0, space);
		if (space != string::npos)
			line = line.erase(0, space + 1);
		else
			line.clear();
		words.push_back(word);
	}

	return words;
}

void output_file(string message, string& filename)
{
	// Open file
	ifstream file(filename);
	if (!file) {
		cout << "Cannot open file " << filename << '\n';
		system("pause");
		exit(1);
	}

	// Output file to the console
	string line;
	cout << message + '\n';
	while (getline(file, line))
		cout << line << '\n';

	// Close file
	file.close();
}