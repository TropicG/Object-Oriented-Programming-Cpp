#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "Student.h"

const int capacity = 1024;

class University {
private:
	Student* students;
	int index = 0;
private:
	void initialise();
public:
	void addStudent();
	void sort();
	void print();
	void clear();
};
#endif
