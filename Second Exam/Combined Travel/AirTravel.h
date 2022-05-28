#ifndef AIR_TRAVEL_H
#define AIR_TRAVEL_H

#include <iostream>

class AirTravel {
protected:
	char* flightNumber;
	int duration;

private:
	void aloc(const int& size);
	void del();

	int getLength(const char* str) const;

	void cpy(const char* flightNumber);

public:
	AirTravel();
	AirTravel(const char* flightNumber, const int& duration);
	AirTravel(const AirTravel& other);
	AirTravel& operator=(const AirTravel& other);
	~AirTravel();

	const char* getFlightNumber() const;
	int getDuration() const;

	void setFlightNumber(const char* flightNumber);
	void setDuration(const int& duration);

	void print() const;
};
#endif
