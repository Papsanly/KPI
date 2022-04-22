#include "header.h"

int main()
{
	std::string out_filename = "user_input.txt";
	std::string in_filename = "manipulated.txt";

	write_to_file(out_filename);
	manipulate_file(out_filename, in_filename);
	output_file("\nUser input text file:", out_filename);
	output_file("\nManipulated text file:", in_filename);

	system("pause");
}