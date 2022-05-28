#include "Virus.h"

std::ostream& operator<<(std::ostream& os, const Virus& virus){
	
	os << virus.getName() << " " << virus.getServility();

	std::cout << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Virus& virus)
{
	char temp[nameMax];
	std::cout << "Enter the name of the virus: ";
	if (is.peek() == '\n') is.ignore();
	is.getline(temp, nameMax);
	virus.setName(temp);

	unsigned helper = 0;
	std::cout << "Enter the servility of the virus: ";
	is >> helper;
	while (is.fail() || helper == 0) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> helper;
	}
	virus.setServility(helper);

	std::cout << std::endl;
	return is;
}


bool Virus::operator<(const Virus& other) const
{
	return this->getServility() < other.getServility();
}

bool Virus::operator<=(const Virus& other) const
{
	return this->getServility() <= other.getServility();
}

Virus::Virus() : name(nullptr), servility(0)
{
}

Virus::Virus(const char* name, const unsigned& servility)
{
	this->setName(name);
	this->setServility(servility);
}

Virus::Virus(const Virus& other)
{
	this->setName(other.getName());
	this->setServility(other.getServility());
}

Virus& Virus::operator=(const Virus& other)
{
	if (this != &other) {
		this->setName(other.getName());
		this->setServility(other.getServility());
	}

	return *this;
}

Virus::~Virus()
{
	delete[] this->name;
}

bool Virus::operator==(const Virus& other) const
{
	return this->getServility() == other.getServility();
}

bool Virus::operator>(const Virus& other) const
{
	return this->getServility() > other.getServility();
}

bool Virus::operator>=(const Virus& other) const
{
	return this->getServility() >= other.getServility();
}

const char* Virus::getName() const
{
	return this->name;
}

unsigned Virus::getServility() const
{
	return this->servility;
}

void Virus::setName(const char* name)
{
	delete[] this->name;
	this->name = new (std::nothrow) char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Virus::setServility(const unsigned& servility)
{
	this->servility = servility;
}
