#ifndef RECTANGULAR
#define RECTANGULAR
#include "Shape.h"
class Rectangular : public Shape {
protected:
	int width = 0;
	int height = 0;

public:
	Rectangular();
	Rectangular(const char* type, const int& width, const int& height);

	int getWigth() const;
	int getHeight() const;

	void setWidth(const int& width);
	void setHeight(const int& height);

	void print() const;
};
#endif
