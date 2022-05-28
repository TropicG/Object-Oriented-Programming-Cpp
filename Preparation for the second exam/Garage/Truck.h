#ifndef TRUCK_H
#define TRUCK_H

#include "Body.h"

const int MAXIMUM_SPEED_TRUCK = 140;
const int LOWEST_MAXIMUM_SPEED_TRUCK = 80;
const int AVARAGE_MAXIMUM_SPEED_TRUCK = (MAXIMUM_SPEED_TRUCK + LOWEST_MAXIMUM_SPEED_TRUCK) / 2;

class Truck : public Body {
public:
	Truck();
	Truck(const std::string& mark, const int& maxSpeed);

	virtual int travelTime(const int& highway, const int& normal, const int& bad) const override;

	virtual void setSpeed(const int& maxSpeed) override;
};
#endif
