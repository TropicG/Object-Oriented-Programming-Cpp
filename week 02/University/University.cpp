#include "University.h"

void University::initialise()
{
	students = new (std::nothrow) Student[capacity];
}

void University::addStudent()
{

	//if we are about to add student we initialise the array
	if (students == nullptr) {
		initialise();
	}

	Student newstudent;
	newstudent.input();
	students[++index] = newstudent;
}

//sorts in ascending order the student with lowest score to highest score
void University::sort()
{
	Student temp;
	for (int i = 0; i < index; ++i) {
		for (int j = i + 1; j < index; ++j) {
			if (students[i].result() > students[j].result()) {
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

void University::print()
{
	for (int i = 0; i < index; ++i) {
		students[i].output();
	}
}

void University::clear()
{
	delete[] students;
}
