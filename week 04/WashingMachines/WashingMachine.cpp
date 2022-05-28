#include "WashingMachine.h"

std::ostream& operator<<(std::ostream& os,const WashingMachine& wash)
{
	os << wash.getManu() << " " << wash.getModel() << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, WashingMachine& wash)
{
	char temp[manuSize + 1];
	std::cout << "Enter the manufactor: ";
	is.ignore();
	is.getline(temp, manuSize + 1, '\n');
	wash.setManu(temp);

	std::cout << "Enter the model: ";
	is.getline(temp, modelSize + 1, '\n');
	wash.setModel(temp);

	int mass = 0;
	std::cout << "Enter the mass: ";
	is >> mass;
	while (std::cin.fail() || mass<=0) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> mass;
	}
	wash.setMass(mass);

	double wat = 0;
	std::cout << "Enter the electricity usage: ";
	is >> wat;
	while (is.fail() || wat <= 0) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> wat;
	}
	wash.setWat(wat);

	int water = 0;
	std::cout << "Enter the water usage: ";
	is >> water;
	while (is.fail() || water <= 0) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> water;
	}
	wash.setWater(water);
	std::cout << std::endl;

	return is;
}

WashingMachine::WashingMachine() : manu(nullptr), model(nullptr), mass(0), wat(0), water(0)
{
}

WashingMachine::WashingMachine(const char* manu, const char* model, const int& mass, const int& wat, const int& water)
{
	this->setManu(manu);
	this->setModel(model);
	this->setMass(mass);
	this->setWat(wat);
	this->setWater(water);
}

WashingMachine& WashingMachine::operator=(const WashingMachine& other)
{
	if (this != &other) {
		this->setManu(other.getManu());
		this->setMass(other.getMass());
		this->setModel(other.getModel());
		this->setWat(other.getWat());
		this->setWater(other.getWater());
	}

	return *this;
}

WashingMachine::~WashingMachine()
{
	delete[] model;
	delete[] manu;
}

bool WashingMachine::operator<(const WashingMachine& other) const
{
	return other.getMass() > this->getMass() && other.getWat() < this->getWat() && other.getWater() < this->getWater();
}

const char* WashingMachine::getManu() const
{
	return this->manu;
}

const char* WashingMachine::getModel() const
{
	return this->model;
}

int WashingMachine::getMass() const
{
	return this->mass;
}

int WashingMachine::getWat() const
{
	return this->wat;
}

int WashingMachine::getWater() const
{
	return this->water;
}

void WashingMachine::setManu(const char* manu)
{
	delete[] this->manu;
	this->manu = new (std::nothrow) char[strlen(manu) + 1];
	strcpy_s(this->manu, strlen(manu) + 1, manu);
}

void WashingMachine::setModel(const char* model)
{
	delete[] this->model;
	this->model = new (std::nothrow) char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

void WashingMachine::setMass(const int& mass)
{
	this->mass = mass;
}

void WashingMachine::setWat(const int& wat)
{
	this->wat = wat;
}

void WashingMachine::setWater(const int& water)
{
	this->water = water;
}
