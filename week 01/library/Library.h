#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"

const int LIBRARY_SIZE = 1024;

struct Library {

	Book books[LIBRARY_SIZE];
	int count = 0;

	void addBook();
	void removeBook();
	void print();
	void clean();
};
#endif
