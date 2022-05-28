#include "Lecurer.h"

Lecurer::Lecurer() : Person()
{
}

Lecurer::Lecurer(const char* name, const double& salary) :
	Person(name)
{
	this->setSalary(salary);
}

Lecurer::Lecurer(const Lecurer& other) : Person(other)
{
	this->setSalary(other.getSalary());
}

double Lecurer::getSalary() const
{
	return this->salary;
}

void Lecurer::setSalary(const double& salary)
{
	this->salary = salary;
}

void Lecurer::read()
{
	Person::read();

	double salary = 0;
	std::cout << "Enter the salary for the teacher: ";
	std::cin >> salary;
	this->setSalary(salary);
}

void Lecurer::print() const
{
	Person::print();
	std::cout << "The teacher's salary is " << this->getSalary();
}
