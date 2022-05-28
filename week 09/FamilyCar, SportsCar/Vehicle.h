#ifndef VEHICLE
#define VEHICLE

class Vehicle {
public:
	virtual void startMovement() = 0;
	virtual void stopMovement() = 0;
};
#endif