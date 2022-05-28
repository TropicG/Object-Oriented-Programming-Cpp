#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>

const int MAX_SUBJECT = 32;

struct Subject {
	char* subject;
	int grade = 0;

	void read();
	void clear();
};
#endif

