#ifndef SQUARE
#define SQUARE
#include "Shape.h"

class Square : public Shape {
private:
	int side = 0;

public:
	Square();
	Square(const char* type, const int& side);

	int getSide() const;

	void setSide(const int& side);

	void print();
};
#endif