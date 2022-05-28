#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>
#include <cstring>

const int subjectSize = 32;

class Subject {
private:
	char* name;
	unsigned grade = 0;
public:
	void input();
	void output();
	void clear();
	unsigned getGrade();
};

#endif
