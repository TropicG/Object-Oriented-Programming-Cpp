#include "FacultyNum.h"

FacultyMember::FacultyMember() : Student(), Lecurer()
{
}

FacultyMember::FacultyMember(const char* name, const unsigned& number, const double& salary) :
	Student(name,number), Lecurer(name, salary)
{
}

FacultyMember::FacultyMember(const FacultyMember& other) : 
	Student(other), Lecurer(other)
{
}

void FacultyMember::read()
{
	Student::read();
	
	double salary = 0;
	std::cout << "Enter the salary for the teacher: ";
	std::cin >> salary;
	this->setSalary(salary);
}

void FacultyMember::print() const
{
	Student::print();
	
	std::cout << "The teacher's salary is " << this->getSalary() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const FacultyMember& fac)
{
	os << fac.getName() << " " << fac.getNumber() << " " << fac.getSalary() << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, FacultyMember& fac)
{
	is >> fac.name >> fac.number >> fac.salary;

	return is;
}
