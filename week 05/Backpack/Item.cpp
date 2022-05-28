#include "Item.h"

Item::Item() : name(nullptr), weight(0), volume(0)
{
}

Item::Item(const char* name, const double& weight, const double& volume)
{
	this->setName(name);
	this->setWeight(weight);
	this->setVolume(volume);
}

Item::Item(const Item& other)
{
	this->setName(other.getName());
	this->setVolume(other.getVolume());
	this->setWeight(other.getWeight());
}

Item& Item::operator=(const Item& other)
{
	if (this != &other) {
		this->setName(other.getName());
		this->setWeight(other.getWeight());
		this->setVolume(other.getVolume());
	}

	return *this;
}

Item::~Item()
{
	delete[] this->name;
}

bool Item::operator==(const Item& item) const
{
	return strcmp(this->getName(), item.getName()) && this->getVolume() == item.getVolume() && this->getWeight() == item.getWeight();
}

bool Item::operator>(const Item& item) const
{
	return this->getVolume() > item.getVolume() && this->getWeight() > item.getWeight();
}

const char* Item::getName() const
{
	return this->name;
}

double Item::getWeight() const
{
	return this->weight;
}

double Item::getVolume() const
{
	return this->volume;
}

void Item::setName(const char* name)
{
	delete[] this->name;
	this->name = new (std::nothrow) char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Item::setWeight(const double& weight)
{
	this->weight = weight;
}

void Item::setVolume(const double& volume)
{
	this->volume = volume;
}

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	os << item.getName() << " " << item.getVolume() << " " << item.getWeight();

	return os;
}

std::istream& operator>>(std::istream& is, Item& item)
{
	char temp[nameSize];
	std::cout << "Enter the name of the item: ";
	if (is.peek() == '\n') is.ignore();
	is.getline(temp, nameSize, '\n');
	item.setName(temp);

	double helper = 0;
	std::cout << "Enter the volume of the item: ";
	is >> helper;
	while(is.fail() || helper < 0){
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> helper;
	}
	item.setVolume(helper);

	std::cout << "Enter the weight of the item: ";
	is >> helper;
	while (is.fail() || helper < 0) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> helper;
	}
	item.setWeight(helper);

	return is;
}
