#pragma once

struct AuthorBooks
{
	char name[512];
	int write_year;
	int publish_year;
};

enum class mode
{
	create,
	append,
	view
};

void create_authors_file(std::string& filename, mode M);
void selective_copy_authors_file(std::string& filename, std::string& copy_filename);
void out_authors_file(std::string& filename, std::string message, bool full);