#include "Pencil.h"

void Pencil::clear()
{
	delete[] this->model;
}

Pencil::Pencil() : model(nullptr), year(0), tough(0)
{
}

Pencil::Pencil(const char* model, const int& year, const int& tough)
{
	this->setModel(model);
	this->setYear(year);
	this->setTough(tough);
}

Pencil::Pencil(const Pencil& other)
{
	this->setModel(other.getModel());
	this->setYear(other.getYear());
	this->setTough(other.getTough());
}

Pencil& Pencil::operator=(const Pencil& other)
{
	if (this != &other) {

		this->clear();

		this->setModel(other.getModel());
		this->setYear(other.getYear());
		this->setTough(other.getTough());
	}

	return *this;
}

Pencil::~Pencil()
{
	delete[] this->model;
}

const char* Pencil::getModel() const
{
	return this->model;
}

int Pencil::getYear() const
{
	return this->year;
}

int Pencil::getTough() const
{
	return this->tough;
}

void Pencil::setModel(const char* model)
{

	int size = strlen(model);
	if (size > MAX_MODEL - 1) {
		std::cout << "Not valid string" << std::endl;
		return;

	}

	this->clear();

	this->model = new char[size + 1];
	if (!model) {
		std::cout << "Failed memory allocation!" << std::endl;
		return;
	}

	strcpy_s(this->model, size, model);
}

void Pencil::setYear(const int& year)
{
	if (year < 0) {
		std::cout << "Invalid year" << std::endl;
		return;
	}

	this->year = year;
}

void Pencil::setTough(const int& tought)
{
	if (tough < 0 || tough > 14) {
		std::cout << "Invalid toughness" << std::endl;
		return;
	}

	this->tough = tought;
}

void Pencil::read()
{
	char model[MAX_MODEL];
	if (std::cin.peek() == '\n') {
		std::cin.ignore();
	}
	std::cout << "Enter the model of the pencil: ";
	std::cin.getline(model, MAX_MODEL, '\n');
	bool failed = std::cin.fail();
	if (failed) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "Enter the year of the pencil: ";
	std::cin >> this->year;
	if (std::cin.fail() || this->year < 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		std::cin >> this->year;
	}

	std::cout << "Enter the toughness of the pencil: ";
	std::cin >> this->tough;
	if (std::cin.fail() || this->tough < 0 || this->tough > 12) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		std::cin >> this->tough;
	}
}

void Pencil::print() const
{
	std::cout << "Model: " << this->model << " Year: " << this->year << " Toughness: " << this->tough << std::endl;

}

std::ostream& operator<<(std::ostream& os, const Pencil& pencil)
{
	os << pencil.year << " " << pencil.tough << " " << pencil.tough << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Pencil& pencil)
{
	is >> pencil.year >> pencil.tough;

	is.ignore();
	char model[MAX_MODEL];
	is.getline(model, MAX_MODEL, '\n');
	is.ignore();
	pencil.setModel(model);

	return is;
}
