#include "Car.h"

Car::Car()
{
}

Car::Car(const double& maxSpeed, const double& currentSpeed, const double& price)
{
	this->setMaxSpeed(maxSpeed);
	this->setCurrentSpeed(currentSpeed);
	this->setPrice(price);
}

Car::Car(const Car& other)
{
	this->setCurrentSpeed(other.getCurrentSpeed());
	this->setMaxSpeed(other.getMaxSpeed());
	this->setPrice(other.getPrice());
}

Car& Car::operator=(const Car& other)
{
	if (this != &other) {
		this->setCurrentSpeed(other.getCurrentSpeed());
		this->setMaxSpeed(other.getMaxSpeed());
		this->setPrice(other.getPrice());
	}

	return *this;
}

double Car::getMaxSpeed() const
{
	return this->maxSpeed;
}

double Car::getCurrentSpeed() const
{
	return this->currentSpeed;
}

double Car::getPrice() const
{
	return this->price;
}

void Car::setMaxSpeed(const double& maxSpeed) 
{
	this->maxSpeed = maxSpeed;
}

void Car::setCurrentSpeed(const double& currentSpeed) 
{
	this->currentSpeed = currentSpeed;
}

void Car::setPrice(const double& price)
{
	this->price = price;
}

void Car::read()
{
	std::cin >> this->maxSpeed >> this->currentSpeed >> this->price;
}

void Car::print() const
{
	std::cout << this->getMaxSpeed() << " " << this->getCurrentSpeed() << " " << this->getPrice() << std::endl;
}
