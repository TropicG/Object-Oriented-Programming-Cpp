#ifndef FAMILYCAR
#define FAMILYCAR
#include "Car.h"

class FamilyCar : public Car {
public:
	FamilyCar();
	FamilyCar(const double& maxSpeed, const double& currentSpeed, const double& price);
	FamilyCar(const FamilyCar& other);
	FamilyCar& operator=(const FamilyCar& other);

	void startMovement();
	void stopMovement();
	void accelerate();

	void read();
	void print();
};

#endif

