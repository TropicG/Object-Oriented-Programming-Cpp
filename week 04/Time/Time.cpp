#include "Time.h"

Time::Time() : hour(0), minute(0)
{
}

Time::Time(const int& hour, const int& minute)
{
	this->setHour(hour);
	this->setMinute(minute);
}

Time& Time::operator=(const Time& other)
{
	if (this != &other) {
		this->setHour(other.getHour());
		this->setMinute(other.getMinute());
	}

	return *this;
}

bool Time::operator==(const Time& other) const
{
	if (this->getHour() == other.getHour() && this->getMinute() == other.getMinute()) {
		return true;
	}
	return false;
}

bool Time::operator>(const Time& other) const
{
	if(this->getHour()==other.getHour()){
		if (this->getMinute() > other.getMinute()) {
			return true;
		}
		else if (this->getMinute() <= other.getMinute()) {
			return false;
		}
	}
	else if (this->getHour() > other.getHour()) {
		return true;
	}
	else {
		return false;
	}
}

bool Time::operator<(const Time& other) const
{
	if (this->getHour() == other.getHour()) {
		if (this->getMinute() < other.getMinute()) {
			return true;
		}
		else if (this->getMinute() >= other.getMinute()) {
			return false;
		}
	}
	else if (this->getHour() < other.getHour()) {
		return true;
	}
	else {
		return false;
	}
}

Time Time::operator+(const Time& other)
{
	return Time(this->getHour() + other.getHour(), this->getMinute() + other.getMinute());
}

Time Time::operator+(const int& hours)
{
	return Time(this->getHour() + hours, this->getMinute());
}

Time Time::operator-(const Time& other)
{
	return Time(abs((int)this->getHour() - (int)other.getHour()), abs((int)this->getMinute() - (int)other.getMinute()));
}

Time Time::operator-(const int& hours)
{
	return Time(abs((int)this->getHour() - hours), this->getMinute());
}

Time& Time::operator+=(const Time& other)
{
	this->setHour(this->getHour() + other.getHour());
	this->setMinute(this->getMinute() + other.getMinute());

	return *this;
}

Time& Time::operator+=(const int& hour)
{
	this->setHour(this->getHour() + hour);

	return *this;
}

Time& Time::operator-=(const Time& other)
{
	this->setHour(abs((int)this->getHour() - (int)other.getHour()));
	this->setMinute(abs((int)this->getMinute() - (int)other.getMinute()));

	return *this;
}

Time& Time::operator-=(const int& hour)
{
	this->setHour(abs((int)this->getHour() - hour));
	
	return *this;
}

unsigned Time::getHour() const
{
	return this->hour;
}

unsigned Time::getMinute() const
{
	return this->minute;
}

void Time::setHour(const int& hour)
{
	this->hour = hour % 24;
}

void Time::setMinute(const int& minute)
{
	this->minute = minute % 60;
}

std::istream& operator>>(std::istream& is, Time& time)
{
	unsigned hour = 0, minutes = 0;

	std::cout << "Enter the hours: ";
	is >> hour;
	while (std::cin.fail()) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> hour;
	}

	std::cout << "Enter the minutes: ";
	is >> minutes;
	while (std::cin.fail()) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		is >> minutes;
	}

	time.setHour(hour);
	time.setMinute(minutes);

	return is;
}

std::ostream& operator<<(std::ostream& os, Time& time)
{
	os << "Hours: " << time.getHour() << " minutes: " << time.getMinute() << std::endl;

	return os;
}
