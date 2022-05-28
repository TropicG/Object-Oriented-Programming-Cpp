#ifndef STUDENTLIST
#define STUDENTLIST
#include "Student.h"

class StudentList {
private:
	Student* students;
	unsigned size = 0;
	unsigned capacity = 0;

private:
	bool inside(const Student& student) const;
	bool inside(const int& faculty) const;

public:

	StudentList(const int& capacity);
	~StudentList();

	void add(const Student& student);
	void remove(const int& faculty);
	void remove(const Student& student);

	bool contains(int facultyNum) const;
	bool contains(const Student& student) const;	

	void print() const;
};


#endif 