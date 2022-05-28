#ifndef CAR_TRAVEL_H
#define CAR_TRAVEL_H

#include <iostream>

class CarTravel {
protected:
	char* regNum;
	float duration;
	float distance;

private:
	void aloc(const int& size);
	void del();

	int getLength(const char* str) const;

	void cpy(const char* regNumber);

public:
	CarTravel();
	CarTravel(const char* regNum, const float& distance, const int& duration);
	CarTravel(const CarTravel& other);
	CarTravel& operator=(const CarTravel& other);
	~CarTravel();
	
	const char* getRegNum() const;
	float getDistance() const;
	int getDuration() const;

	void setRegNum(const char* regNum);
	void setDuration(const int& duration);
	void setDistance(const float& distance);

	void print() const;
};
#endif