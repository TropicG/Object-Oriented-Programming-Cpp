#ifndef COMBINED_TRIP_H
#define COMBINED_TRIP_h

#include "AirTravel.h"
#include "CarTravel.h"

class CombinedTrip : public AirTravel, CarTravel{
private:
	char* destinations;
	int freeTime;

private:
	void aloc(const int& size);
	void del();

	int getLength(const char* str) const;

	void cpy(const char* destinations);

public:
	CombinedTrip();
	CombinedTrip(const char* destinations, const int& freeTime,
		const char* flightNumber, const int& durationPlane, const char* carNumber, const float& distance, const int& durationCar);
	CombinedTrip(const CombinedTrip& other);
	CombinedTrip& operator=(const CombinedTrip& other);
	~CombinedTrip();

	const char* getDestinations() const;
	int getFreeTime() const;

	int getWholeDuration() const;

	void setDestinations(const char* destnations);
	void setFreeTime(const int& freeTime);

	void print() const;
};
#endif