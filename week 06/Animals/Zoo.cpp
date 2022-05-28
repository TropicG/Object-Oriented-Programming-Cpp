#include "Zoo.h"

void Zoo::clearName()
{
	delete[] this->name;
}

void Zoo::clearFamilies()
{
	for (int i = 0; i < this->getSize(); ++i) {
		delete this->families[i];
	}
}

bool Zoo::inside(const char* name) const
{
	for (int i = 0; i < this->getSize(); ++i) {
		if (strcmp(this->families[i]->getName(), name) == 0) {
			return true;
		}
	}

	return false;
}

Family* Zoo::getFamily(const char* name)
{
	for (int i = 0; i < this->getSize(); ++i) {
		if (strcmp(this->families[i]->getName(), name) == 0) {
			return this->families[i];
		}
	}

	return nullptr;
}

Zoo::Zoo() : name(nullptr), cap(zooMaxCap)
{
}

Zoo::Zoo(const Zoo& other)
{
	this->setName(other.getName());
	this->setCap(other.getCap());
	this->setSize(other.getSize());

	for (int i = 0; i < this->getSize(); ++i) {
		this->families.push_back(new Family(other[i]));
	}
}

Zoo& Zoo::operator=(const Zoo& other)
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

Zoo::~Zoo()
{
	this->clearName();
	this->clearFamilies();
}

void Zoo::addFamily(const Family& family)
{
	if (this->inside(family.getName())) {
		throw FamilyThere();
	}

	if (this->getSize() + 1 > this->getCap()) {
		throw ZooOverflow();
	}

	this->families.push_back(new Family(family));
	this->size++;
}

void Zoo::removeFamily(const Family& family)
{
	if (!this->inside(family.getName())) {
		throw FamilyNotThere();
	}

	if (this->getSize() == 0) {
		throw ZooEmpty();
	}

	for (int i = 0; i < this->getSize(); ++i) {
		if (*this->families[i] == family) {

			this->families.erase(this->families.begin() + i);
			break;
		}
	}
	this->size--;
}

void Zoo::addToFamily(const char* famName, const Animal& animal)
{
	if (!inside(famName)) throw FamilyNotThere();
	Family* temp = this->getFamily(famName);
	temp->addMember(animal);
}

void Zoo::removeFromFamily(const char* famName, const Animal& animal)
{
	if (!inside(famName)) throw FamilyNotThere();
	Family* temp = this->getFamily(famName);
	temp->removeMember(animal);
}

bool Zoo::operator==(const Zoo& other) const
{
	return strcmp(this->getName(), other.getName()) == 0;
}

Family& Zoo::operator[](const unsigned& index) const
{
	return *this->families[index];
}

Family Zoo::operator[](const unsigned& index)
{
	return *this->families[index];
}

const char* Zoo::getName() const
{
	return this->name;
}

unsigned Zoo::getCap() const
{
	return this->cap;
}

unsigned Zoo::getSize() const
{
	return this->size;
}

void Zoo::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Zoo::setCap(const unsigned& cap)
{
	this->cap = cap;
}

void Zoo::setSize(const unsigned& size)
{
	this->size = size;
}

std::ostream& operator<<(std::ostream& os, const Zoo& zoo)
{
	os << "The name of the Zoo is " << zoo.getName() << " and has " << zoo.getSize() << " members" << std::endl;
	for (int i = 0; i < zoo.getSize(); ++i) {
		os << zoo[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, Zoo& zoo)
{
	char name[zooNameMax];
	std::cout << "Enter the name of the zoo: ";
	if (is.peek() == '\n') is.ignore();
	is.getline(name, zooNameMax, '\n');
	bool failed = is.fail();
	if (failed) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	zoo.setName(name);

	unsigned cap = 0;
	std::cout << "Enter the number of families in the zoo: ";
	is >> cap;
	while (is.fail() || cap > zooMaxCap) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> cap;
	}
	zoo.setCap(cap);

	return is;
}
