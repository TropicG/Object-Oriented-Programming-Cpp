#ifndef VAN_H
#define VAN_H

#include "Body.h"

const int MAXIMUM_SPEED_VAN = 160;
const int LOWEST_MAXIMUM_SPEED_VAN = 120;
const int AVARAGE_MAXIMUM_SPEED_VAN = (MAXIMUM_SPEED_VAN + LOWEST_MAXIMUM_SPEED_VAN) / 2;

class Van : public Body {
public:
	Van();
	Van(const std::string& mark, const int& maxSpeed);

	virtual int travelTime(const int& highway, const int& normal, const int& bad) const override;

	virtual void setSpeed(const int& maxSpeed) override;
};
#endif