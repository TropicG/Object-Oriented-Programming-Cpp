#include "HardDrive.h"

HardDrive::HardDrive() : Component()
{
}

HardDrive::HardDrive(const char* desc, const int& id) : Component(desc, id)
{
}

HardDrive::HardDrive(const HardDrive& other) : Component(other)
{
}

void HardDrive::read()
{
	Component::read();
}

void HardDrive::print() const
{
	Component::print();
}
