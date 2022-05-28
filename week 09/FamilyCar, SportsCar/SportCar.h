#ifndef SPORTCAR
#define SPORTCAR
#include "Car.h"

class SportCar : public Car {
public:
	SportCar();
	SportCar(const double& maxSpeed, const double& currentSpeed, const double& price);
	SportCar(const SportCar& other);
	SportCar& operator=(const SportCar& other);

	void startMovement();
	void stopMovement();
	void accelerate();

	void read();
	void print() const;
};
#endif

