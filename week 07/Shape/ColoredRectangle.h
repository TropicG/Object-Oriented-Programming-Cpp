#ifndef COLOREDRECTANGLE
#define COLOREDRECTANGLE
#include "Rectangular.h"

class ColoredRectangle : public Rectangular {
private:
	std::string color;

public:
	ColoredRectangle();
	ColoredRectangle(const char* color, const int& width, const int& height, const char* type);

	std::string getColor() const;

	void setColor(const char* color);

	void print();
};
#endif