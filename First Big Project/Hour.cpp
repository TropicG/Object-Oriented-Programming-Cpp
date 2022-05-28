#include "Hour.h"

bool Hour::valid(const int& hour, const int& minute) const
{
    return hour <= 24 && hour >= 0 && minute <= 59 && minute >= 0;
}

Hour::Hour() : hour(0), minute(0)
{
}

Hour::Hour(const int& hour, const int& minute)
{
    this->setHour(hour);
    this->setMinute(minute);
}

Hour::Hour(const Hour& other)
{
    this->setHour(other.getHour());
    this->setMinute(other.getMinute());
}

Hour& Hour::operator=(const Hour& other)
{
    if (this != &other) {
        this->setHour(other.getHour());
        this->setMinute(other.getMinute());
    }

    return *this;
}

Hour Hour::operator-(const Hour& other) const
{
    
    //if the argument has higher hour than *this we return zero Hour object
    if (this->hour == other.hour) {
        if (this->minute < other.minute) return Hour(0, 0);
    }
    else if (this->hour < other.hour) return Hour(0, 0);


    int mins = 0, hours = 0;

    //if the this minutes are lower than other's minute
    if (this->minute < other.minute) {

        mins = (this->minute + 60) - other.minute;
        hours = (this->hour - 1) - other.hour;
    }
    else {
        hours = this->hour - other.hour;
        mins = this->minute - other.minute;
    }

    return Hour(hours, mins);
}

Hour& Hour::operator+=(const Hour& other)
{
    this->hour += other.hour;
    this->minute += other.minute;

    if (this->minute >= 60) {
        this->hour++;
        this->minute -= 60;
    }

    return *this;
}

bool Hour::operator==(const Hour& other) const
{
    return this->hour == other.hour && this->minute == other.minute;
}

bool Hour::operator>=(const Hour& other) const
{
    if (this->hour == other.hour) return this->minute >= other.minute;
    else return this->hour >= other.hour;
}

bool Hour::operator<=(const Hour& other) const
{
    if (this->hour == other.hour) return this->minute <= other.minute;
    return this->hour <= other.hour;
}

bool Hour::operator>(const Hour& other) const
{
    if (this->hour == other.hour) return this->minute > other.minute;
    else return this->hour > other.hour;
}

bool Hour::operator<(const Hour& other) const
{
    if (this->hour == other.hour) return this->minute < other.minute;
    return this->hour < other.hour;
}

int Hour::getHour() const
{
    return this->hour;
}

int Hour::getMinute() const
{
    return this->minute;
}

void Hour::setHour(const int& hour)
{
    this->hour = hour;
}

void Hour::setMinute(const int& minute)
{
    this->minute = minute;
}

void Hour::read()
{
    while (true) {
        std::cin >> this->hour;
        std::cin >> this->minute;

        if (valid(hour, minute)) break;
        else std::cout << "Invalid hour, try again: ";
    }
}

void Hour::print() const
{
    if (this->hour < 10 && this->minute < 10) {
        std::cout << "0" << this->hour << ":" << "0" << this->minute;
    }

    else if (this->hour < 10 && this->minute >= 10) {
        std::cout << "0" << this->hour << ":" << this->minute;
    }

    else if (this->hour >= 10 && this->minute < 10) {
        std::cout << this->hour << ":" << "0" << this->minute;
    }

    else std::cout << this->hour << ":" << this->minute;
}