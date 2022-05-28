#ifndef SHAPE
#define SHAPE
#include <iostream>
#include <cstring>
#include <string>

class Shape {
protected:
	std::string type;

public:
	Shape();
	Shape(const char* type);

	const std::string getType() const;

	void setType(const char* type);

	void print();
};
#endif
