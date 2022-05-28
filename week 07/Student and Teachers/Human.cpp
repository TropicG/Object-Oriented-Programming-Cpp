#include "Human.h"

Human::Human()
{
}

Human::Human(const char* name, const char* family, const unsigned& age)
{
	this->setName(name);
	this->setFamily(family);
	this->setAge(age);
}

Human::Human(const Human& other)
{
	this->setName(other.getName().c_str());
	this->setFamily(other.getName().c_str());
	this->setAge(other.getAge());
}

const std::string Human::getName() const
{
	return this->name;
}

const std::string Human::getFamily() const
{
	return this->family;
}

unsigned Human::getAge() const
{
	return this->age;
}

void Human::setName(const char* name)
{
	this->name = name;
}

void Human::setFamily(const char* family)
{
	this->family = family;
}

void Human::setAge(const unsigned& age)
{
	this->age = age;
}

void Human::print() const
{
	std::cout << this->getName() << " " << this->getFamily() << " " << this->getAge() << std::endl;
}

void Human::read()
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

	char family[nameMax];
	std::cout << "Enter the person's family name: ";
	if (std::cin.peek() == '\n') std::cin.ignore();
	std::cin.getline(family, nameMax, '\n');
	failed = std::cin.fail();
	if (failed) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	this->setFamily(family);

	unsigned age = 0;
	std::cout << "Enter the person's age: ";
	std::cin >> age;
	while (std::cin.fail() || age == 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, please try again: ";
		std::cin >> age;
	}
	this->setAge(age);
}
