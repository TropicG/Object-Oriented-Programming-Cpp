#include "Car.h"

Car::Car() : Body()
{
}

Car::Car(const std::string& mark, const int& maxSpeed)
	: Body(mark)
{
	this->setSpeed(maxSpeed);
}

int Car::travelTime(const int& highway, const int& normal, const int& bad) const
{
	return (highway + normal + bad) / this->maxSpeed;
}

void Car::setSpeed(const int& maxSpeed)
{
	if (maxSpeed < LOWEST_MAXIMUM_SPEED_CAR || maxSpeed > MAXIMUM_SPEED_CAR) {
		this->maxSpeed = AVARAGE_MAXIMUM_SPEED_CAR;
	}
	else this->maxSpeed = maxSpeed;
}
