#include "Processor.h"

Processor::Processor() : Component()
{
}

Processor::Processor(const char* desc, const int& id) : Component(desc,id)
{
}

Processor::Processor(const Processor& other) : Component(other)
{
}

void Processor::read()
{
	Component::read();
}

void Processor::print() const
{
	Component::print();
}
