#include "Book.h"

void Book::read()
{
	char temp[MAX_STRING];
	std::cout << "Book title: ";
	std::cin.ignore();
	std::cin.getline(temp, MAX_STRING);
	if (temp[0] >= 'a' && temp[0] <= 'z'){
		temp[0] += ('A' - 'a');
	}
	title = new (std::nothrow) char[strlen(temp)+1];
	strcpy_s(title, strlen(temp),temp);
	title[strlen(temp)] = '\0';

	std::cout << "Book author: ";
	std::cin.getline(temp, MAX_STRING);
	author = new (std::nothrow) char[strlen(temp)+1];
	strcpy_s(author, strlen(temp),temp);
	author[strlen(temp)] = '\0';

	std::cout << "ISBN: ";
	std::cin >> isbn;
}

void Book::print()
{
	std::cout << "Book title: " << title << std::endl;
	std::cout << "Book author: " << author << std::endl;
	std::cout << "Book ISBN: " << isbn << std::endl;
	std::cout << std::endl;
}

void Book::clean()
{
	delete[] title;
	delete[] author;
}
