#include "Person.h"

Person::Person()
{
}

Person::Person(const char* name)
{
	this->setName(name);
}

Person::Person(const Person& other)
{
	this->setName(other.getName().c_str());
}

const std::string Person::getName() const
{
	return this->name;
}

void Person::setName(const char* name)
{
	this->name = name;
}

void Person::read()
{
	char name[nameMax];
	std::cout << "Enter the name of the person: ";
	if (std::cin.peek() == '\n') std::cin.ignore();
	std::cin.getline(name, nameMax, '\n');
	bool failed = std::cin.fail();
	if (failed) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	this->setName(name);
}

void Person::print() const
{
	std::cout << "The name of the person is " << this->getName() << std::endl;
}
