#include "Engine.h"
bool Engine::valid(const char* type) const
{
	if (strcmp(type, "benzin") != 0 && strcmp(type, "disel") != 0 && strcmp(type, "hybrid") != 0
		&& strcmp(type, "electrical") != 0) {
		return false;
	}
	return true;
}
void Engine::clear()
{
	delete[] type;
}
Engine::Engine() : horsePower(0), mass(0)
{
	this->setType("unknown");
}
Engine::Engine(const unsigned& horsePower, const unsigned& mass, const char* type)
{
	this->setHorse(horsePower);
	this->setMass(mass);
	this->setType(type);
}
Engine& Engine::operator=(const Engine& other)
{
	if (this != &other) {
		this->setHorse(other.getHorse());
		this->setMass(other.getMass());
		this->setType(other.getType());
	}

	return *this;
}
Engine::~Engine()
{
	clear();
}
bool Engine::operator==(const Engine& other) const
{
	bool equal = this->getHorse() == other.getHorse() && this->getMass() == other.getMass()
		&& strcmp(this->getType(), other.getType()) == 0;
	return equal;
}
unsigned Engine::getHorse() const
{
	return this->horsePower;
}
unsigned Engine::getMass() const
{
	return this->mass;
}
const char* Engine::getType() const
{
	return this->type;
}
void Engine::setHorse(const int& horsePower)
{
	this->horsePower = horsePower;
}
void Engine::setMass(const int& mass)
{
	this->mass = mass;
}
void Engine::setType(const char* type)
{
	clear();

	if (!valid(type)) {
		this->type = new (std::nothrow) char[strlen("unknown") + 1];
		strcpy_s(this->type, strlen("unknown") + 1, "unknown");
	}
	else {
		this->type = new (std::nothrow) char[strlen(type) + 1];
		strcpy_s(this->type, strlen(type) + 1, type);
	}
}

void Engine::print() const
{
	std::cout << "The type of the engine is " << getType() << ", the horse power of the engine is " << getHorse() << " and the mass is " << getMass() << std::endl;

}

void Engine::read()
{
	std::cout << "Enter the horse power: ";
	std::cin >> horsePower;
	
	std::cout << "Enter the mass: ";
	std::cin >> mass;

	char temp[16];
	std::cout << "Enter the type of the engine: ";
	std::cin.ignore();
	std::cin.getline(temp, 16, '\n');
	this->setType(temp);
}
