#ifndef STUDENT_H
#define STUDENT_H
#include "Subject.h"

const int MAX_NAME = 32, EGN_SIZE = 10, FACULTY_SIZE = 5, GRADES = 5;

struct Student
{
	char name[MAX_NAME];
	char egn[EGN_SIZE];
	char faculty[FACULTY_SIZE];
	Subject grades[GRADES];

	void correct(char* str);
	bool valid(const char* str);
	void read();
	void print();
	int getMonth();
	float avarage();
	void clear();

};
#endif
