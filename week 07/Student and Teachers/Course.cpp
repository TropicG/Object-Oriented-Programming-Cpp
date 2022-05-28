#include "Course.h"

Course::Course()
{
}

Course::Course(const char* name)
{
	this->setName(name);
}

Course::Course(const Course& other)
{
	this->setName(other.getName().c_str());
}

bool Course::operator==(const Course& other) const
{
	return this->getName() == other.getName();
}

const std::string Course::getName() const
{
	return this->name;
}

void Course::setName(const char* name)
{
	this->name = name;
}
