#include "SportCar.h"

SportCar::SportCar() : Car()
{
}

SportCar::SportCar(const double& maxSpeed, const double& currentSpeed, const double& price) :
	Car(maxSpeed, currentSpeed, price)
{
}

SportCar::SportCar(const SportCar& other) : Car(other)
{
}

SportCar& SportCar::operator=(const SportCar& other)
{
	Car::operator=(other);

	return *this;
}

void SportCar::startMovement()
{
	std::cout << "Starting the engine" << std::endl;
	this->setCurrentSpeed(20);
	std::cout << "Current speed is " << std::endl;
}

void SportCar::stopMovement()
{
	std::cout << "Stoping the engine" << std::endl;
	this->setCurrentSpeed(0);
}

void SportCar::accelerate()
{
	std::cout << "Accelerating" << std::endl;
	if (this->currentSpeed + 50 > this->maxSpeed) {
		this->currentSpeed = this->maxSpeed;
	}
	else {
		this->currentSpeed += 50;
	}
	std::cout << "Current speed is " << this->getCurrentSpeed() << std::endl;
}

void SportCar::read()
{
	Car::read();
}

void SportCar::print() const
{
	Car::print();
}
