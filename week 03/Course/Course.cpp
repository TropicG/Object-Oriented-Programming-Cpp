#include "Course.h"

void Course::initialise(const int& capacity, const char* name)
{
	this->course = new (std::nothrow) Student[capacity];

	this->name = new (std::nothrow) char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

bool Course::inside(const Student& student) const
{
	for (int i = 0; i < size; ++i) {
		if (course[i].equal(student))
			return true;
	}
	return false;
}

Course::Course() : size(0), capacity(maxCapacity)
{
	initialise(maxCapacity, "Unknown");
}

Course::Course(const int& capacity, const char* name) : size(0), capacity(capacity)
{
	initialise(capacity, name);
}

Course::~Course()
{
	delete[] course;
}

void Course::enrolStudent(const Student& student)
{
	if (inside(student)) {
		std::cout << "This student was already added!";
		return;
	}

	this->course[size++] = student;
}

void Course::enrolStudents(const std::vector<Student> students)
{
	int size = students.size();
	for (int i = 0; i < size; ++i) {
		enrolStudent(students[i]);
	}
}

Student Course::getAt(const int& pos)
{
	if (pos < 0 || pos >= size){
	return Student();
	}
	return this->course[pos];
}

char* Course::getName() const
{
	return this->name;
}

void Course::printInformation() const
{
	std::cout << "The name of the course is: " << this->getName() << std::endl;
	for (int i = 0; i < size; ++i) {
		this->course[i].print();
	}
}
