#include "StudentList.h"

bool StudentList::inside(const Student& student) const
{
	for (int i = 0; i < size; ++i) {
		if (students[i].equal(student)) {
			return true;
		}
	}
	return false;
}

bool StudentList::inside(const int& faculty) const
{
	for (int i = 0; i < size; ++i) {
		if (students[i].getFaculty() == faculty) {
			return true;
		}
	}
	return false;
}

StudentList::StudentList(const int& capacity) : size(0)
{
	this->capacity = capacity;
	this->students = new (std::nothrow) Student[capacity];
}

StudentList::~StudentList()
{
	delete[] students;
}

void StudentList::add(const Student& student)
{
	if (inside(student)) {
		std::cout << "This student is already in the list! " << std::endl;
		return;
	}
	this->students[size++] = student;
	std::cout << "Student added!" << std::endl;
}

void StudentList::remove(const int& faculty)
{
	if (!inside(faculty)) {
		std::cout << "There is not such student in the list";
		return;
	}

	if (size == 0) {
		std::cout << "There are no students in the list" << std::endl;
		return;
	}

	int loc = 0;
	for (int i = 0; i < size; ++i) {
		if (students[i].getFaculty() == faculty) {
			loc = i;
			break;
		}
	}

	students[loc] = students[size - 1];
	size--;
	std::cout << "Student removed" << std::endl;
}

void StudentList::remove(const Student& student)
{
	this->remove(student.getFaculty());
}

bool StudentList::contains(int facultyNum) const
{
	return inside(facultyNum);
}

bool StudentList::contains(const Student& student) const
{
	return inside(student);
}

void StudentList::print() const
{

	if (size == 0) {
		std::cout << "There are no students in the list" << std::endl;
		return;
	}

	for (int i = 0; i < size; ++i) {
		this->students[i].print();
	}
}
