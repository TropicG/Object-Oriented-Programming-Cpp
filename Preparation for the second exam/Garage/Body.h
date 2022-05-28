#ifndef BODY_H
#define BODY_H

#include <string>

class Body {
protected:
	std::string mark;
	int maxSpeed;

public:
	Body();
	Body(const std::string& mark);

	virtual int travelTime(const int& highway, const int& normal, const int& bad) const = 0;

	int getSpeed() const;
	std::string getMark() const;

	virtual void setSpeed(const int& maxSpeed) = 0;
	void setMark(const std::string& mark);
};
#endif