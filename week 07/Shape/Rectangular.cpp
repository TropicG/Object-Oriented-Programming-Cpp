#include "Rectangular.h"

Rectangular::Rectangular() : Shape()
{
}

Rectangular::Rectangular(const char* type, const int& width, const int& height) : Shape(type)
{
    this->setWidth(width);
    this->setHeight(height);
}

int Rectangular::getWigth() const
{
    return this->width;
}

int Rectangular::getHeight() const
{
    return this->height;
}

void Rectangular::setWidth(const int& width)
{
    this->width = width;
}

void Rectangular::setHeight(const int& height)
{
    this->height = height;
}

void Rectangular::print()
{
    Shape::print();
    std::cout << this->getHeight() << " " << this->getWigth() << std::endl;
}
