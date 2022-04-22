#pragma once

#include <string>
#include <vector>

//Writes user input to a file
void write_to_file(std::string& filename);

//Creates new manipulated file
void manipulate_file(std::string& out_filename, std::string& in_filename);

//Manipulate the file line according to the task
std::string manipulate(std::string line);

//Split line into vector of words
std::vector<std::string> split(std::string line);

//Output file content to the console
void output_file(std::string message, std::string& filename);