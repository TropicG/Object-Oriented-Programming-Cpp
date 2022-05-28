#include "Time.h"

Time::Time() : hour(0), minute(0)
{
}

Time::Time(const int& hour, const int& minute)
{
	this->setHour(hour);
	this->setMinute(minute);
}

Time::Time(const Time& other)
{
	this->setMinute(other.getMinutes());
	this->setHour(other.getHours());
}

void Time::toNYC()
{
	if (this->hour - 5 < 0) {
		this->hour = 24 - (5 - this->hour);
	}
	else
	{
		this->hour -= 5;
	}
}

void Time::toSofia()
{
	if (this->hour + 2 >= 24) {
		this->hour = 0 + (24 - this->hour + 2);
	}
	else {
		this->hour += 2;
	}
}

void Time::toMoscow()
{
	if (this->hour + 3 >= 24)
	{
		this->hour = 0 + (24 - this->hour + 3);
	}
	else
	{
		this->hour += 3;
	}
}

int Time::getHours() const
{
	return this->hour;
}

int Time::getMinutes() const
{
	return this->minute;
}

void Time::setHour(const int& hour)
{
	if (hour > 24) {
		this->hour = 0;
	}
	else
	{
		this->hour = hour;
	}
}

void Time::setMinute(const int& minutes)
{
	if (minutes > 60) {
		this->minute = 0;
	}
	else
	{
		this->minute = minutes;
	}
}

void Time::print() const
{
	std::cout << hour << ":" << minute << std::endl;
}
