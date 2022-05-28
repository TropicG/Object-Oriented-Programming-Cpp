#include "Visual.h"

void Visual::clear()
{
	delete[] this->color;
}

Visual::Visual() : doors(0), spoiler(false)
{
	this->setColor("unknown");
}

Visual::Visual(const unsigned& doors, const char* spoiler, const char* color)
{
	this->setDoors(doors);
	this->setSpoiler(spoiler);
	this->setColor(color);
}

Visual& Visual::operator=(const Visual& other)
{
	if (this != &other) {
		this->setColor(other.getColor());
		this->setDoors(other.getDoors());
		this->setSpoiler(other.getSpoiler());
	}

	return *this;
}

Visual::~Visual()
{
	clear();
}

bool Visual::operator==(const Visual& other) const
{
	bool equal = strcmp(this->getColor(), other.getColor()) == 0 && this->getDoors() == other.getDoors() &&
		strcmp(this->getSpoiler(), other.getSpoiler()) == 0;
	return equal;
}

unsigned Visual::getDoors() const
{
	return this->doors;
}

const char* Visual::getSpoiler() const
{
	return this->spoiler ? "yes" : "no";
}

const char* Visual::getColor() const
{
	return this->color;
}

void Visual::setDoors(const unsigned& doors)
{
	this->doors = doors;
}

void Visual::setSpoiler(const char* spoiler)
{
	this->spoiler = (strcmp(spoiler, "yes") == 0) ? true : false;
}

void Visual::setColor(const char* color)
{
	clear();
	this->color = new (std::nothrow) char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

void Visual::print() const
{
	if (spoiler) {
		std::cout << "The car has " << getDoors() << " in " << getColor() << " color and has spoiler" << std::endl;
	}
	else {
		std::cout << "The car has " << getDoors() << " in " << getColor() << " color and has no spoiler" << std::endl;
	}
}

void Visual::read()
{
	unsigned helper = 0;
	char temp[colorSize];

	std::cout << "Enter the doors of the car: ";
	std::cin >> helper;
	if (helper > 4) helper = 4;
	this->setDoors(helper);

	std::cout << "Enter the color of the car: ";
	std::cin.ignore();
	std::cin.getline(temp, colorSize, '\n');
	this->setColor(temp);

	std::cout << "Enter does the car has spoiler or no: ";
	std::cin >> temp;
	this->setSpoiler(temp);
}
