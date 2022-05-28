#ifndef SCHOOL_H
#define SCHOOL_H
#include "Student.h"

struct School {
	Student students[128];
	int count = 0;

	void addStudent();
	void bornMarch();
	void printBestStudent();
	void clear();
};

#endif
