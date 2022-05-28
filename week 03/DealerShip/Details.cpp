#include "Details.h"

void Details::clear()
{
	delete[] this->manufac;
	delete[] this->model;
}

Details::Details() : manufac(nullptr), model(nullptr), year(1885)
{
}

Details::Details(const char* manufac, const char* model, const unsigned& year)
{
	this->setManu(manufac);
	this->setModel(model);
	this->setYear(year);
}

Details& Details::operator=(const Details& other)
{
	if (this != &other) {
		this->setManu(other.getManufac());
		this->setModel(other.getModel());
		this->setYear(other.getYear());
	}

	return *this;
}

Details::~Details()
{
	clear();
}

bool Details::operator==(const Details& other) const
{
	bool equal = strcmp(this->getManufac(), other.getManufac()) == 0 &&
		strcmp(this->getModel(), other.getModel()) == 0 && this->getYear() == other.getYear();

	return equal;
}

const char* Details::getManufac() const
{
	return this->manufac;
}

const char* Details::getModel() const
{
	return this->model;
}

unsigned Details::getYear() const
{
	return this->year;
}

void Details::setManu(const char* manu)
{
	delete[] this->manufac;
	this->manufac = new (std::nothrow) char[strlen(manu) + 1];
	strcpy_s(this->manufac, strlen(manu) + 1, manu);
}

void Details::setModel(const char* model)
{
	delete[] this->model;
	this->model = new (std::nothrow) char[strlen(model) + 1];
	strcpy_s(this->model, strlen(model) + 1, model);
}

void Details::setYear(const unsigned& year)
{
	this->year = year;
}

void Details::print() const
{
	std::cout << "The name of the manufactor is " << getManufac() << " and its model is " << getModel() << " created in " << getYear() << std::endl;
}

void Details::read()
{
	char temp[modelSize + 1];
	std::cin.ignore();
	std::cout << "Enter the manufactorer: ";
	std::cin.getline(temp, manufacturerSize, '\n');
	this->setManu(temp);

	std::cout << "Enter the model: ";
	std::cin.getline(temp, modelSize, '\n');
	this->setModel(temp);

	unsigned year = 0;
	std::cout << "Enter the manufactored year: ";
	std::cin >> year;
	while (std::cin.fail() || year < 1885 || year > 2022) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		std::cin >> year;
	}
	this->setYear(year);
}
