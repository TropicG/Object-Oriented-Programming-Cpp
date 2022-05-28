#ifndef COURSE
#define COURSE
#include "Student.h"
#include <vector>

const int maxCapacity = 256;

class Course {
private:
	Student* course;
	unsigned size = 0;
	unsigned capacity = 0;
	char* name;

private:
	void initialise(const int& capacity, const char* name);
	bool inside(const Student& student) const;

	
public:
	Course();
	Course(const int& capacity, const char* name);
	~Course();

	void enrolStudent(const Student& student);
	void enrolStudents(const std::vector<Student> students);

	Student getAt(const int& pos);
	char* getName() const;

	void printInformation() const;
};

#endif