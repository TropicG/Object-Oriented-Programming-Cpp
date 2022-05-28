#include "Fauna.h"

void Fauna::clearName()
{
	delete[] this->name;
}

void Fauna::clearFamilies()
{
	for (int i = 0; i < this->getSize(); ++i) {
		delete this->families[i];
	}
}

bool Fauna::inside(const char* name)
{
	for (int i = 0; i < this->getSize(); ++i) {
		if (strcmp(this->families[i]->getName(), name) == 0) {
			return true;
		}
	}

	return false;
}

Family* Fauna::getFamily(const char* name)
{
	for (int i = 0; i < this->getSize(); ++i) {
		if (strcmp(this->families[i]->getName(), name) == 0) {
			return this->families[i];
		}
	}

	return nullptr;
}

Fauna::Fauna() : name(nullptr), cap(faunaCapMax), size(0)
{
}

Fauna::Fauna(const char* name, const unsigned cap)
{
	this->setName(name);
	this->setCap(cap);
}

Fauna::Fauna(const Fauna& other)
{
	this->setName(other.getName());
	this->setCap(other.getCap());
	this->setSize(other.getSize());
	for (int i = 0; i < this->getSize(); ++i) {
		this->families.push_back(new Family(other[i]));
	}
}

Fauna& Fauna::operator=(const Fauna& other)
{
	if (this != &other) {

		this->setName(other.getName());
		this->setCap(other.getCap());
		this->setSize(other.getSize());

		this->clearFamilies();
		for (int i = 0; i < this->getSize(); ++i) {
			this->families.push_back(new Family(other[i]));
		}
	}

	return *this;
}

Fauna::~Fauna()
{
	this->clearFamilies();
	this->clearName();
}

void Fauna::addFamily(const Family& fam)
{
	if (this->inside(fam.getName())) {
		throw FamilyThere(); 
	}

	if (this->getSize() + fam.getSize() > this->getCap()) {
		throw FaunaOverflow();
	}

	this->families.push_back(new Family(fam));
	this->size++;
}

void Fauna::removeFamily(const Family& fam)
{
	if (!this->inside(fam.getName())) {
		throw FamilyNotThere();
	}

	if (this->getSize() == 0) {
		throw FaunaEmpty();
	}

	for (int i = 0; i < this->getSize(); ++i) {
		if (*this->families[i] == fam) {

			this->families.erase(families.begin() + i);
			break;
		}
	}
	this->size--;
}

void Fauna::addToFamily(const char* famName, const Animal& ani)
{
	if (!inside(famName)) throw FamilyNotThere();
	Family* temp = this->getFamily(famName);
	temp->addMember(ani);
}

void Fauna::removeFromFamily(const char* famName, const Animal& ani)
{
	if (!inside(famName)) throw FamilyNotThere();
	Family* temp = this->getFamily(famName);
	temp->removeMember(ani);
}

bool Fauna::operator==(const Fauna& other) const
{
	return strcmp(this->getName(), other.getName()) == 0;
}

Family& Fauna::operator[](const unsigned& index) const
{
	return *families[index];
}

Family Fauna::operator[](const unsigned& index)
{
	return *families[index];
}

const char* Fauna::getName() const
{
	return this->name;
}

unsigned Fauna::getCap() const
{
	return this->cap;
}

unsigned Fauna::getSize() const
{
	return this->size;
}

void Fauna::setName(const char* name)
{
	clearName();
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Fauna::setCap(const unsigned& cap)
{
	this->cap = cap;
}

void Fauna::setSize(const unsigned& size)
{
	this->size = size;
}

std::ostream& operator<<(std::ostream& os, const Fauna& fauna)
{
	os << "The name of the fauna is " << fauna.getName() << " and has " << fauna.getSize() << " members" << std::endl;
	for (int i = 0; i < fauna.getSize(); ++i) {
		os << fauna[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, Fauna& fauna)
{
	char name[faunaNameMax];
	std::cout << "Enter the name of the fauna: ";
	if (is.peek() == '\n') is.ignore();
	is.getline(name, faunaNameMax, '\n');
	bool failed = is.fail();
	if (failed) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	fauna.setName(name);

	unsigned cap = 0;
	std::cout << "Enter the capacity for the fauna: ";
	is >> cap; 
	while (is.fail() || cap > faunaCapMax) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> cap;
	}
	fauna.setCap(cap);

	return is;
}
