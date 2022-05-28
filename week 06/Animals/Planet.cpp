#include "Planet.h"

void Planet::clearName()
{
	delete[] this->name;
}

void Planet::clearFaunas()
{
	for (int i = 0; i < this->getFaunaSize(); ++i) {
		delete this->faunas[i];
	}
}

void Planet::clearZoos()
{
	for (int i = 0; i < this->getZooSize(); ++i) {
		delete this->zoos[i];
	}
}

bool Planet::insideFauna(const char* faunaName) const
{
	return false;
}

bool Planet::insideZoo(const char* zooName) const
{
	return false;
}

Fauna* Planet::getFauna(const char* faunaName)
{
	return nullptr;
}

Zoo* Planet::getZoo(const char* zooName)
{
	return nullptr;
}

Planet::Planet() : name(nullptr), faunaCap(faunaCapMax), zooCap(zooMaxCap)
{
}

Planet::Planet(const char* name, const unsigned& faunaCap, const unsigned& zooCap)
{
	this->setName(name);
	this->setFaunaCap(faunaCap);
	this->setZooCap(zooCap);
}

Planet::Planet(const Planet& other)
{
	this->setName(other.getName());
	this->setFaunaCap(other.getFaunaCap());
	this->setFaunaSize(other.getFaunaSize());
	this->setZooCap(other.getZooCap());
	this->setZooSize(other.getZooSize());

	for (int i = 0; i < this->getFaunaSize(); ++i) {
		this->faunas.push_back(new Fauna(other.atFauna(i)));
	}
	for (int i = 0; i < this->getZooSize(); ++i) {
		this->zoos.push_back(new Zoo(other.atZoo(i)));
	}
}

Planet& Planet::operator=(const Planet& other)
{
	if (this != &other) {

		this->setName(other.getName());
		this->setFaunaCap(other.getFaunaCap());
		this->setFaunaSize(other.getFaunaSize());
		this->setZooCap(other.getZooCap());
		this->setZooSize(other.getZooSize());

		this->clearFaunas();
		this->clearZoos();
		for (int i = 0; i < this->getFaunaSize(); ++i) {
			this->faunas.push_back(new Fauna(other.atFauna(i)));
		}
		for (int i = 0; i < this->getZooSize(); ++i) {
			this->zoos.push_back(new Zoo(other.atZoo(i)));
		}
	}

	return *this;
}

Planet::~Planet()
{
	this->clearFaunas();
	this->clearZoos();
	this->clearName();
}

void Planet::addFauna(const Fauna& fauna)
{
	if (insideFauna(fauna.getName())) {
		throw FaunaThere();
	}

	if (this->getFaunaSize() + 1 > this->getFaunaCap()) {
		throw PlanetFaunaOverflow();
	}

	this->faunas.push_back(new Fauna(fauna));
	this->faunaSize++;
}

void Planet::addFamilyInFauna(const char* faunaName, const Family& family)
{
	if (!insideFauna(faunaName)) {
		throw FaunaNotThere();
	}
	Fauna* temp = this->getFauna(faunaName);
	temp->addFamily(family);
}

void Planet::addAnimalInFamilyInFauna(const char* faunaName, const char* familyName, const Animal& animal)
{
	if (!insideFauna(faunaName)) {
		throw FaunaNotThere();
	}
	Fauna* temp = this->getFauna(faunaName);
	temp->addToFamily(familyName, animal);
}

void Planet::removeFauna(const char* faunaName)
{
	if (!insideFauna(faunaName)) {
		throw FaunaNotThere();
	}

	if (this->getFaunaSize() == 0) {
		throw PlanetFaunaEmpty();
	}

	for (int i = 0; i < this->getFaunaSize(); ++i) {
		if (strcmp(this->faunas[i]->getName(), faunaName) == 0) {

			this->faunas.erase(faunas.begin() + i);
			break;
		}
	}

	this->faunaSize--;
}

void Planet::removeFamilyInFauna(const char* faunaName, const Family& family)
{
	if (!insideFauna(faunaName)) {
		throw FaunaNotThere();
	}
	Fauna* temp = this->getFauna(faunaName);
	temp->removeFamily(family);
}

void Planet::removeAnimalInFamilyInFauna(const char* faunaName, const char* familyName, const Animal& animal)
{
	if (!insideFauna(faunaName)) {
		throw FaunaNotThere();
	}
	Fauna* temp = this->getFauna(faunaName);
	temp->removeFromFamily(familyName, animal);
}

void Planet::addZoo(const Zoo& zoo)
{
	if (insideZoo(zoo.getName())) {
		//throw ZooThere();
	}

	if (this->getZooSize() + 1 > this->getZooCap()) {
		//throw PlanetZooOverflow();
	}

	this->zoos.push_back(new Zoo(zoo));
	this->zooSize++;
}

void Planet::addFamilyInZoo(const char* zooName, const Family& family)
{
	if (!insideZoo(zooName)) {
		//throw ZooNotThere();
	}
	Zoo* temp = this->getZoo(zooName);
	temp->addFamily(family);
}

void Planet::addAnimalInFamilyInZoo(const char* zooName, const char* familyName, const Animal& animal)
{
	if (!insideZoo(zooName)) {
		//throw ZooNotThere();
	}
	Zoo* temp = this->getZoo(zooName);
	temp->addToFamily(familyName, animal);
}

void Planet::removeZoo(const char* zooName)
{
	if (!insideZoo(zooName)) {
		//throw ZooNotThere();
	}

	if (this->getZooSize() == 0) {
		//throw PlanetZooEmpty();
	}

	for (int i = 0; i < this->getZooSize(); ++i) {
		if (strcmp(this->zoos[i]->getName(), zooName) == 0) {

			this->zoos.erase(this->zoos.begin() + i);
			break;
		}
	}

	this->zooSize--;
}

void Planet::removeFamilyInZoo(const char* zooName, const Family& family)
{
	if (!insideZoo(zooName)) {
		//throw ZooNotThere();
	}
	Zoo* temp = this->getZoo(zooName);
	temp->removeFamily(family);
}

void Planet::removeAnimalInFamilyInZoo(const char* zooName, const char* familyName, const Animal& animal)
{
	if (!insideZoo(zooName)) {
		//throw ZooNotThere();
	}
	Zoo* temp = this->getZoo(zooName);
	temp->removeFromFamily(familyName, animal);
}

Fauna& Planet::atFauna(const unsigned& index) const
{
	return *this->faunas[index];
}

Fauna Planet::atFauna(const unsigned& index)
{
	return *this->faunas[index];
}

Zoo& Planet::atZoo(const unsigned& index) const
{
	return *this->zoos[index];
}

Zoo Planet::atZoo(const unsigned& index)
{
	return *this->zoos[index];
}

const char* Planet::getName() const
{
	return this->name;
}

unsigned Planet::getFaunaCap() const
{
	return this->faunaCap;
}

unsigned Planet::getZooCap() const
{
	return this->zooCap;
}

unsigned Planet::getFaunaSize() const
{
	return this->faunaSize;
}

unsigned Planet::getZooSize() const
{
	return this->zooSize;
}

void Planet::setName(const char* name)
{
	clearName();
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Planet::setFaunaCap(const unsigned& faunaCap)
{
	this->faunaCap = faunaCap;
}

void Planet::setZooCap(const unsigned& zooCap)
{
	this->zooCap = zooCap;
}

void Planet::setFaunaSize(const unsigned& faunaSize)
{
	this->faunaSize = faunaSize;
}

void Planet::setZooSize(const unsigned& zooSize)
{
	this->zooSize = zooSize;
}

std::ostream& operator<<(std::ostream& os, const Planet& planet)
{
	os << "The planet's name is " << planet.getName() << " and has " << planet.getFaunaSize() << " faunas and " << planet.getZooSize() << " zoos" << std::endl;
	for (int i = 0; i < planet.getFaunaSize(); ++i) {
		os << planet.atFauna(i);
	}
	for (int i = 0; i < planet.getZooSize(); ++i) {
		os << planet.atZoo(i);
	}

	return os;
}

std::istream& operator>>(std::istream& is, Planet& planet)
{
	char name[planetNameMax];
	std::cout << "Enter the planet's name: ";
	if (is.peek() == '\n') is.ignore();
	is.getline(name, planetNameMax, '\n');
	bool failed = is.fail();
	if (failed) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	planet.setName(name);

	unsigned faunaCap = 0;
	std::cout << "Enter the capacity for the faunas: ";
	is >> faunaCap;
	while (is.fail() || faunaCap > faunaCapMax) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, please try again: ";
		is >> faunaCap;
	}
	planet.setFaunaCap(faunaCap);

	unsigned zooCap = 0;
	std::cout << "Enter the capacity for the zoos: ";
	is >> zooCap;
	while (is.fail() || zooCap > zooMaxCap) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, please try again: ";
		is >> zooCap;
	}
	planet.setZooCap(zooCap);

	return is;
}
