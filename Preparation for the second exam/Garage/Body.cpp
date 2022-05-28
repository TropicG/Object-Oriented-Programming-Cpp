#include "Body.h"

Body::Body() : mark("none"), maxSpeed(0)
{
}

Body::Body(const std::string& mark) :
	mark(mark), maxSpeed(0)
{
}

int Body::getSpeed() const
{
	return this->maxSpeed;
}

std::string Body::getMark() const
{
	return this->mark;
}

void Body::setMark(const std::string& mark)
{
	this->mark = mark;
}
