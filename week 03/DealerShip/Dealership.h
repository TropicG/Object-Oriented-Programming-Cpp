#ifndef DEALERSHIP
#define DEALERSHIP
#include "Car.h"

const int maxCap = 1024;

class Dealership {
private:
	Car* cars = nullptr; 
	int size = 0;

private:
	void initialise();
	bool inside(const Car& car) const;

public:
	Dealership();
	~Dealership();
	
	void addCar(const Car& car);
	void removeCar(const Car& car);
	void changeCar(const Car& car, const char* what);

	void print() const;
};

#endif
