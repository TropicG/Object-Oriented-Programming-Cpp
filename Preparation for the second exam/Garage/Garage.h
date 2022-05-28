#ifndef GARAGE_H
#define GARAGE_H

#include "Car.h"
#include "Truck.h"
#include "Van.h"

const int MAX_CAP = 128;

class Garage {
private:
	Body** cars;
	int size = 0;
	int cap = 0;

private:
	void aloc(const int& cap);
	void del();

public:
	Garage();
	Garage(const int& cap);
	Garage(const Garage& other);
	Garage& operator=(const Garage& other);
	~Garage();

	void add(Body* vehicle);

	int getSuccsessfullOrderCount(const int& highway, const int& normal, const int& bad, const int& time);
};
#endif

