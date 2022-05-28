#include "Car.h"


void Car::print() const
{
	this->eng.print();
	this->vis.print();
	this->d.print();
	std::cout << std::endl;
}

void Car::read() 
{
	this->eng.read();
	this->vis.read();
	this->d.read();
	std::cout << std::endl;
}

Engine& Car::getEngine()
{
	return this->eng;
}

Visual& Car::getVisual()
{
	return this->vis;
}

Details& Car::getDetails()
{
	return this->d;
}

Car::Car()
{
}

Car::Car(const Engine& eng, const Visual& vis, const Details& d)
{
	this->setEngine(eng);
	this->setVisual(vis);
	this->setDetails(d);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other) {
		this->setEngine(other.getEngine());
		this->setVisual(other.getVisual());
		this->setDetails(other.getDetails());
	}

	return *this;
}

bool Car::operator==(const Car& other) const
{
	bool equal = this->getEngine() == other.getEngine() && this->getVisual() == other.getVisual() && this->getDetails() == other.getDetails();
	return equal;
}

const Engine& Car::getEngine() const
{
	return this->eng;
}

const Visual& Car::getVisual() const
{
	return this->vis;
}

const Details& Car::getDetails() const
{
	return this->d;
}

void Car::setEngine(const Engine& eng)
{
	this->eng = eng;
}

void Car::setVisual(const Visual& vis)
{
	this->vis = vis;
}

void Car::setDetails(const Details& d)
{
	this->d = d;
}
