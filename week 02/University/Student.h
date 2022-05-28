#ifndef STUDENT_H
#define STUDENT_H
#include "Subject.h"

const int gradesCount = 5, nameSize = 64, egnSize = 10, facultySize= 5;

class Student {
private:
	char* name;
	char* egn;
	char* faculty;
	Subject grades[gradesCount];
private:
	bool valid(const char* str);
public:

	void input();
	void output();
	void clear();

	double result();
};
#endif

