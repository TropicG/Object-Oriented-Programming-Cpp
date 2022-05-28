#include "Dealership.h"

void Dealership::initialise()
{
	this->cars = new (std::nothrow) Car[maxCap];
}

bool Dealership::inside(const Car& car) const
{
	for (int i = 0; i < size; ++i) {
		if (cars[i] == car) {
			return true;
		}
	}
	return false;
}

Dealership::Dealership() : size(0)
{
	this->initialise();
}

Dealership::~Dealership()
{
	delete[] cars;
}

void Dealership::addCar(const Car& car)
{
	if (inside(car)) {
		std::cout << "This car was already added" << std::endl;
		return;
	}

	this->cars[size] = car;
	size++;

	std::cout << "Car succsesfully added!" << std::endl;
	std::cout << std::endl;
}

void Dealership::removeCar(const Car& car)
{
	if (!inside(car)) {
		std::cout << "This car is not inside" << std::endl;
		return;
	}

	int pos = 0;
	for (int i = 0; i < size; ++i) {
		if (cars[i] == car) {
			pos = i;
			break;
		}
	}

	cars[pos] = cars[size - 1];
	size--;

	std::cout << "Car succsesfully removed" << std::endl;
	std::cout << std::endl;
}

void Dealership::changeCar(const Car& car, const char* what)
{
	if (!inside(car)) {
		std::cout << "This car is not in here" << std::endl;
		return;
	}

	int loc = 0;
	for (int i = 0; i < size; ++i) {
		if (this->cars[i] == car) {
			loc = i;
			break;
		}
	}

	unsigned helper = 0;
	char temp[64];

	if (strcmp(what, "horsepower") == 0) {
		std::cout << "Enter the new horse power for the car: ";
		std::cin >> helper;
		while (std::cin.fail() || helper == 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid argument, try again: ";
			std::cin >> helper;
		}

		this->cars[loc].getEngine().setHorse(helper);
	}
	else if (strcmp(what, "mass") == 0) {
		std::cout << "Enter the new mass for the car: ";
		std::cin >> helper;
		while (std::cin.fail() || helper == 0) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid argument, try again: ";
			std::cin >> helper;
		}

		this->cars[loc].getEngine().setMass(helper);
	}
	else if (strcmp(what, "type") == 0) {
		std::cout << "Enter the new type for the car: ";
		std::cin >> temp;

		this->cars[loc].getEngine().setType(temp);
	}
	else if (strcmp(what, "doors") == 0) {
		std::cout << "Enter the doors for the car: ";
		std::cin >> helper;
		while (std::cin.fail() || helper== 0 || helper > 4) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid argument, try again: ";
			std::cin >> helper;
		}

		this->cars[loc].getVisual().setDoors(helper);
	}
	else if (strcmp(what, "spoiler") == 0) {
		std::cout << "Enter the do you want spoiler: ";
		std::cin >> temp;

		this->cars[loc].getVisual().setSpoiler(temp);
	}
	else {
		std::cout << "Enter the color for the car: ";
		std::cin >> temp;

		this->cars[loc].getVisual().setColor(temp);
	}
	
	std::cout << "Car succsesfully changed!" << std::endl;
	std::cout << std::endl;
}

void Dealership::print() const
{
	for (int i = 0; i < size; ++i) {
		this->cars[i].print();
	}
}
