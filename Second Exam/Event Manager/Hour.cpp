#include "Hour.h"

Hour::Hour() : hour(0), minutes(0)
{
}

Hour::Hour(const int& hour, const int& minutes)
{
	if (hour <= MIN_HOUR || hour >= MAX_HOUR) {
		this->setHour(MIN_HOUR);
	}
	else {
		this->setHour(hour);
	}

	if (minutes <= MIN_MINUTES || minutes >= MAX_MINUTES) {
		this->setMinutes(MIN_MINUTES);
	}
	else {
		this->setMinutes(minutes);
	}
}

Hour& Hour::operator=(const Hour& other)
{
	this->setHour(other.getHour());
	this->setMinutes(other.getMinutes());

	return *this;
}

Hour Hour::operator-(const Hour& other) const
{

	int hour = this->hour;
	int minutes = this->minutes;

	if (this->minutes < other.minutes) {

		minutes = minutes + 60 - other.minutes;
		hour--;
		
		hour -= other.hour;

		return Hour(hour, minutes);
	}
	else {
		minutes -= other.minutes;
		hour -= other.hour;

		return Hour(hour, minutes);
	}
}

bool Hour::operator<=(const Hour& event) const
{
	if (this->hour == event.hour)
		return this->minutes <= event.minutes;

	return this->hour <= event.hour;
}

bool Hour::operator>=(const Hour& event) const
{
	if (this->hour == event.hour)
		return this->minutes >= event.minutes;

	return this->hour >= event.hour;
}

int Hour::getHour() const
{
	return this->hour;
}

int Hour::getMinutes() const
{
	return this->minutes;
}

void Hour::setHour(const int& hour)
{
	this->hour = hour;
}

void Hour::setMinutes(const int& minutes)
{
	this->minutes = minutes;
}
