#include "Student.h"

Student::Student() : Person()
{
}

Student::Student(const char* name, const unsigned& number) :
	Person(name)
{
	this->setNumber(number);
}

Student::Student(const Student& other) : Person(other)
{
	this->setNumber(other.getNumber());
}

unsigned Student::getNumber() const
{
	return this->number;
}

void Student::setNumber(const unsigned& num)
{
	this->number = num;
}

void Student::read()
{
	Person::read();

	unsigned num = 0;
	std::cout << "Enter the student's number: ";
	std::cin >> num;
	this->setNumber(num);
}

void Student::print() const
{
	Person::print();
	std::cout << "The student's number is " << this->getNumber() << std::endl;
}
