#include "Horo.h"

Horo::Horo() : name(nullptr), tact(nullptr), field(nullptr)
{
}

Horo::Horo(const char* name, const char* tack, const char* field)
{
	setName(name);
	setTack(tack);
	setField(field);
}

Horo::Horo(const Horo& other)
{
	setName(other.getName());
	setTack(other.getTack());
	setField(other.getField());
}

Horo::~Horo()
{
	delete[] name;
	delete[] tact;
	delete[] field;
}

char* Horo::getName() const
{
	return this->name;
}

char* Horo::getTack() const
{
	return this->tact;
}

char* Horo::getField() const
{
	return this->field;
}

void Horo::setName(const char* name)
{
	delete[] this->name;
	this->name = new (std::nothrow) char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Horo::setTack(const char* tack)
{
	delete[] this->tact;
	this->tact = new (std::nothrow) char[strlen(tack) + 1];
	strcpy_s(this->field, strlen(field) + 1, field);
}

void Horo::setField(const char* field)
{
	delete[] this->field;
	this->field = new (std::nothrow) char[strlen(field) + 1];
	strcpy_s(this->field, strlen(field) + 1, field);
}
