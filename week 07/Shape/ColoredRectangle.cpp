#include "ColoredRectangle.h"

ColoredRectangle::ColoredRectangle() : Rectangular()
{
}

ColoredRectangle::ColoredRectangle(const char* color, const int& width, const int& height, const char* type) :
	Rectangular(type,width,height)
{
	this->setColor(color);
}

std::string ColoredRectangle::getColor() const
{
	return this->color;
}

void ColoredRectangle::setColor(const char* color)
{
	this->color = color;
}

void ColoredRectangle::print()
{
	Rectangular::print();
	std::cout << this->getColor() << std::endl;
}
