#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>


struct Point {
	double x = 0, y=0;

	void read();
	void print();
	void distanceToCenter();
	void distanceToOther();
};

#endif
