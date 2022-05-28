#ifndef STUDENT
#define STUDENT
#include <iostream>
#include <cstring>

const int maj = 5, maxMaj = 40, nameSize = 51;
const char bachalors[maj][maxMaj] = { "Informatics", "Computer Science", "Software Engineering", "Mathematics", "Mathematics and Informatics" };

class Student
{
private:
	unsigned facultyNumber;
	char name[nameSize];
	char major[maxMaj];
	unsigned group;

private:
	void setName(const char* name);
	void setFaculty(const int& faculty);

	bool inside(const char* str) const;

public:
	Student();
	Student(const unsigned& facultyNumber, const char* name, const char* major, const int& group);
	Student(const Student& other);

	void setMajor(const char* name);
	void setGroup(const int& group);

	unsigned getFaculty() const;
	const char* getName() const;
	const char* getMajor() const;
	unsigned getGruop() const;

	void print() const;
	void read();
};
#endif 