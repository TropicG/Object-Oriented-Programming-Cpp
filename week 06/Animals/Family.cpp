#include "Family.h"

bool Family::inside(const Animal& animal) const
{
    for (int i = 0; i < getSize(); ++i) {
        if (*this->members[i] == animal) {
            return true;
        }
    }

    return false;
}

void Family::clearFamName()
{
    delete[] this->name;
}

void Family::clearMembers()
{
    for (int i = 0; i < getSize(); ++i) {
        delete members[i];
    }
}

Family::Family() : name(nullptr),size(0), cap(famCap)
{
}

Family::Family(const char* name,const unsigned& cap)
{
    this->setCap(cap);
    this->setName(name);
}

Family::Family(const Family& other)
{
    this->setName(other.getName());
    this->setCap(other.getCap());
    this->setSize(other.getSize());
    for (int i = 0; i < getSize(); ++i) {
        this->members.push_back(new Animal(other[i]));
    }
}

Family& Family::operator=(const Family& other)
{
    if (this != &other) {

        this->clearMembers();

        this->setName(other.getName());
        this->setCap(other.getCap());
        this->setSize(other.getSize());
        for (int i = 0; i < getSize(); ++i) {
            this->members.push_back(new Animal(other[i]));
        }
    }

    return *this;
}

Family::~Family()
{
    clearMembers();
    clearFamName();
}

void Family::addMember(const Animal& animal)
{
    if (getSize() == getCap()) {
        throw FamilyOverflow();
    }
    
    if (inside(animal)) {
        throw AnimalThere();
    }

    this->members.push_back(new Animal(animal));
    this->size++;
}

void Family::removeMember(const Animal& animal)
{

    if (getSize() == 0) {
        throw EmptyFamily();
    }

    if (!inside(animal)) {
        throw AnimalNotThere();
    }

    for (int i = 0; i < getSize(); ++i) {
        if (*members[i] == animal) {

            this->members.erase(members.begin() + i);
            break;
        }
    }
    this->size--;
}

bool Family::operator==(const Family& other)
{
    return strcmp(this->getName(), other.getName()) == 0;
}

Animal& Family::operator[](const int& index) const
{
    return *members[index];
}

Animal Family::operator[](const int& index)
{
    return *members[index];
}

unsigned Family::getSize() const
{
    return this->size;
}

unsigned Family::getCap() const
{
    return this->cap;
}

const char* Family::getName() const
{
    return this->name;
}


void Family::setName(const char* name)
{
    clearFamName();
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}

void Family::setSize(const unsigned& size)
{
    this->size = size;
}

void Family::setCap(const unsigned& cap)
{
    this->cap = cap;
}

std::ostream& operator<<(std::ostream& os, const Family& fam)
{
    os << "The name of the family is " << fam.getName() << " and has " << fam.getSize() << " members: " << std::endl;
    for (int i = 0; i < fam.getSize(); ++i) {
        os << fam[i];
    }

    return os;
}

std::istream& operator>>(std::istream& is, Family& fam)
{
    char temp[famNameMax];
    std::cout << "Enter the name of the family: ";
    if (is.peek() == '\n') is.ignore();
    is.getline(temp, famNameMax, '\n');
    bool failed = is.fail();
    if (failed) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    fam.setName(temp);

    unsigned cap = 0;
    std::cout << "Enter the capacity of the family: ";
    is >> cap;
    while (is.fail() || cap > famCap) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid argument, please try again: ";
        is >> cap;
    }
    fam.setCap(cap);

    return is;
}
