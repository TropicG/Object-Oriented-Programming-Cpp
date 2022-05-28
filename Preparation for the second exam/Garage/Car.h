#ifndef CAR_H
#define CAR_H

#include "Body.h"

const int MAXIMUM_SPEED_CAR = 240;
const int LOWEST_MAXIMUM_SPEED_CAR = 180;
const int AVARAGE_MAXIMUM_SPEED_CAR = (MAXIMUM_SPEED_CAR + LOWEST_MAXIMUM_SPEED_CAR) / 2;

class Car : public Body {
public:
	Car();
	Car(const std::string& mark, const int& maxSpeed);

	virtual int travelTime(const int& highway, const int& normal, const int& bad) const override;

	virtual void setSpeed(const int& maxSpeed) override ;
};
#endif