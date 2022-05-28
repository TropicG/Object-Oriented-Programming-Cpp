#include "Ram.h"

Ram::Ram() : Component()
{
}

Ram::Ram(const char* desc, const int& id) : Component(desc,id)
{
}

Ram::Ram(const Ram& other) : Component(other)
{
}

void Ram::read()
{
	Component::read();
}

void Ram::print() const
{
	Component::print();
}
