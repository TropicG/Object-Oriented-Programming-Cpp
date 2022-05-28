#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <cmath>

class Triangle {
private:

	unsigned a = 0, b = 0, c = 0;

	bool valid();

public:

	void input();
	void output();
	int per();
	double area();


};

#endif
