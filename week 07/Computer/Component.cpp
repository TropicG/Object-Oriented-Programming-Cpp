#include "Component.h"

Component::Component()
{
}

Component::Component(const char* desc, const int& id)
{
    this->setDesc(desc);
    this->setId(id);
}

Component::Component(const Component& other)
{
    this->setId(other.getId());
    this->setDesc(other.getDesc().c_str());
}

const std::string Component::getDesc() const
{
    return this->desc;
}

int Component::getId() const
{
    return this->id;
}

void Component::setDesc(const char* desc)
{
    this->desc = desc;
}

void Component::setId(const int& id)
{
    this->id = id;
}

void Component::print() const
{
    std::cout << this->getDesc() << " " << this->getId() << std::endl;
}

void Component::read()
{
    int id = 0;
    std::cout << "Enter the id of the component: ";
    std::cin >> id;
    this->setId(id);
    
    char desc[128];
    std::cout << "Enter the description for the component: ";
    std::cin.ignore();
    std::cin.getline(desc, 128, '\n');
    this->setDesc(desc);
}
