#include "Shape.h"

Shape::Shape() : type(nullptr)
{
}

Shape::Shape(const char* type)
{
    this->setType(type);
}


const std::string Shape::getType() const
{
    return this->type;
}

void Shape::setType(const char* type)
{
    this->type = type;
}

void Shape::print()
{
    std::cout << this->getType() << std::endl;
}
