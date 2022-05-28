#include "Square.h"

Square::Square() : Shape()
{
}

Square::Square(const char* type, const int& side) : Shape(type)
{
}

int Square::getSide() const
{
	return this->side;
}

void Square::setSide(const int& side)
{
	this->side = side;
}

void Square::print()
{
	Shape::print();
	std::cout << this->getSide() << std::endl;
}
