#include "Van.h"

Van::Van() : Body()
{
}

Van::Van(const std::string& mark, const int& maxSpeed) :
	Body(mark)
{
	this->setSpeed(maxSpeed);
}

int Van::travelTime(const int& highway, const int& normal, const int& bad) const
{
	int highwayTime = highway / maxSpeed;
	int normalTime = normal / (maxSpeed * 2);
	int badTime = bad / (maxSpeed * 3);

	return highwayTime + normalTime + badTime;
}

void Van::setSpeed(const int& maxSpeed)
{
	if (maxSpeed < LOWEST_MAXIMUM_SPEED_VAN || maxSpeed > MAXIMUM_SPEED_VAN) {
		this->maxSpeed = AVARAGE_MAXIMUM_SPEED_VAN;
	}
	else this->maxSpeed = maxSpeed;
}
