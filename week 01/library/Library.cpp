#include "Library.h"

void Library::addBook()
{
	if (count + 1 >= LIBRARY_SIZE) {
		std::cout << "No space left in the library" << std::endl;
	}
	else {
		Book newbook;
		newbook.read();
		books[count++] = newbook;
	}
}

void Library::removeBook() {

	char temp[ISBN_SIZE];
	std::cout << "Enter the isbn code to delete: ";
	std::cin.getline(temp, ISBN_SIZE);

	for (int i = 0; i < count; ++i) {

		if (strcmp(books[i].isbn, temp) == 0) {
			books[i] = books[--count];
			break;
		}
	}
}

void Library::print() {
	for (int i = 0; i < count; ++i) {
		books[i].print();
	}
}

void Library::clean() {
	for (int i = 0; i < count; ++i) {
		books[i].clean();
	}
}
