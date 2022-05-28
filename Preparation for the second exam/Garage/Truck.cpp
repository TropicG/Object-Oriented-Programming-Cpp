#include "Truck.h"

Truck::Truck() : Body() 
{
}

Truck::Truck(const std::string& mark, const int& maxSpeed) :
	Body(mark)
{
	this->setSpeed(maxSpeed);
}

int Truck::travelTime(const int& highway, const int& normal, const int& bad) const
{
	int highwayTime = highway / (maxSpeed * 2);
	int normalTime = normal / (maxSpeed * 4);
	int badTime = bad / 10;

	return highwayTime + normalTime + badTime;
}

void Truck::setSpeed(const int& maxSpeed)
{
	if (maxSpeed < LOWEST_MAXIMUM_SPEED_TRUCK || maxSpeed > MAXIMUM_SPEED_TRUCK) {
		this->maxSpeed = AVARAGE_MAXIMUM_SPEED_TRUCK;
	}
	else this->maxSpeed = maxSpeed;
}
