#ifndef CAR
#define CAR
#include "Vehicle.h"
#include <iostream>

class Car : public Vehicle {
protected:
	double maxSpeed = 0;
	double currentSpeed = 0;
	double price = 0;

public:
	Car();
	Car(const double& maxSpeed, const double& currentSpeed, const double& price);
	Car(const Car& other);
	Car& operator=(const Car& other);

	virtual void startMovement() = 0;
	virtual void stopMovement() = 0;
	virtual void accelerate() = 0;

	double getMaxSpeed() const;
	double getCurrentSpeed() const;
	double getPrice() const;

	void setMaxSpeed(const double& maxSpeed);
	void setCurrentSpeed(const double& currentSpeed);
	void setPrice(const double& price);

	void read();
	void print() const;
};
#endif