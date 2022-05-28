#include "Animal.h"

void Animal::clearName()
{
    delete[] this->name;
}

Animal::Animal() : name(nullptr)
{
}

Animal::Animal(const char* name)
{
    this->setName(name);
}

Animal::Animal(const Animal& other)
{
    this->setName(other.getName());
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other) {
        this->setName(other.getName());
    }

    return *this;
}

Animal::~Animal()
{
    clearName();
}

bool Animal::operator==(const Animal& other)
{
    return strcmp(this->getName(), other.getName()) == 0;
}

const char* Animal::getName() const
{
    return this->name;
}

void Animal::setName(const char* name)
{
    clearName();
    this->name = new (std::nothrow) char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}

std::ostream& operator<<(std::ostream& os, const Animal& animal)
{
    os << animal.getName() << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Animal& animal)
{
    char name[aniNameMax];
    std::cout << "Enter the name of the animal: ";
    if (is.peek() == '\n') is.ignore();
    is.getline(name, aniNameMax, '\n');
    
    bool failed = is.fail();
    if (failed) {
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    animal.setName(name); 

    return is;
}
