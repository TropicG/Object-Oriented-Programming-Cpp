#include "Website.h"

void Website::load(Facebook& face)
{
	std::ifstream file;
	file.open("database.txt");
	
	file >> face;

	file.close();
}

void Website::save(const Facebook& face)
{
	std::ofstream file;
	file.open("database.txt", std::ofstream::out | std::ofstream::trunc);
	file.close();

	std::ofstream file1;
	file1.open("database.txt");

	file1 << face;
}
