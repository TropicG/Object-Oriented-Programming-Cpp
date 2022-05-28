#include "Student.h"

bool Student::inside(const Course& course) const
{
	for (int i = 0; i < this->attending.size(); ++i) {
		if (*this->attending[i] == course) {
			return true;
		}
	}

	return false;
}

Student::Student() : Human()
{
}

Student::Student(std::string name, std::string family, const unsigned& age, const unsigned& facultyNum, std::string bach) :
	Human(name.c_str(),family.c_str(),age)
{
	this->setFaculty(facultyNum);
	this->setBachelor(bach.c_str());
}

Student::Student(const Student& other) : Human(other)
{
	this->setFaculty(other.getFaculty());
	this->setBachelor(other.getBachelor().c_str());
}

Student::~Student()
{
	for (int i = 0; i < this->attending.size(); ++i) {
		delete this->attending[i];
	}
}

void Student::addCourse(const Course& course)
{
	if (inside(course)) {
		throw CourseAdded();
	}

	this->attending.push_back(new Course(course));
}

void Student::removeCourse(const Course& course)
{
	if (!inside(course)) {
		throw CourseNotAdded();
	}

	for (int i = 0; i < this->attending.size(); ++i) {
		if (*this->attending[i] == course) {
			this->attending.erase(this->attending.begin() + i);
		}
	}
}

Course& Student::operator[](const unsigned& index) const
{
	return *this->attending[index];
}

Course Student::operator[](const unsigned& index)
{
	return *this->attending[index];
}

unsigned Student::getFaculty() const
{
	return this->facultyNum;
}

const std::string Student::getBachelor() const
{
	return this->bach;
}

void Student::setFaculty(const unsigned& fac)
{
	this->facultyNum = fac;
}

void Student::setBachelor(const std::string& bach)
{
	this->bach = bach;
}
