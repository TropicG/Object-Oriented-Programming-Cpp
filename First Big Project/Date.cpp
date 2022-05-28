#include "Date.h"

bool Date::valid(const int& day, const int& month, const int& year) const
{
    if (day >= 32 || day <= 0 || month >= 13 || month <= 0 || year <= 0) return false;

    if (day >= 30 && (month == 4 || month == 6 || month == 9 || month == 11)) return false;

    bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    if (!leap && day >= 29 && month == 2) return false;

    return true;
}

Date::Date() : day(0), month(0), year(0)
{
}

Date::Date(const int& day, const int& month, const int& year)
{
    this->setDay(day);
    this->setMonth(month);
    this->setYear(year);
}

Date::Date(const Date& other)
{
    this->setDay(other.getDay());
    this->setMonth(other.getMonth());
    this->setYear(other.getYear());
}

Date& Date::operator=(const Date& other)
{
    if (this != &other) {
        this->setDay(other.getDay());
        this->setMonth(other.getMonth());
        this->setYear(other.getYear());
    }

    return *this;
}

bool Date::operator==(const Date& other) const
{
    return this->day == other.day && this->month == other.month && this->year == other.year;
}

bool Date::operator!=(const Date& other) const
{
    return this->day != other.day || this->month != other.month || this->year != other.year;
}

bool Date::operator>=(const Date& other) const
{
    if (this->year == other.year) {
        if (this->month == other.month) return this->day >= other.day;
        else return this->month >= other.month;
    }
    else return this->year >= other.year;
}

bool Date::operator<=(const Date& other) const
{
    if (this->year == other.year) {
        if (this->month == other.month) return this->day <= other.day;
        else return this->month <= other.month;
    }
    else return this->year <= other.year;
}

bool Date::operator>(const Date& other) const
{
    if (this->year == other.year) {
        if (this->month == other.month) return this->day > other.day;
        else return this->month > other.month;
    }
    else return this->year > other.year;
}

bool Date::operator<(const Date& other) const
{
    if (this->year == other.year) {
        if (this->month == other.month) return this->day < other.day;
        else return this->month < other.month;
    }
    else return this->year < other.year;
}

int Date::getDay() const
{
    return this->day;
}

int Date::getMonth() const
{
    return this->month;
}

int Date::getYear() const
{
    return this->year;
}

void Date::setDay(const int& day)
{
    this->day = day;
}

void Date::setMonth(const int& month)
{
    this->month = month;
}

void Date::setYear(const int& year)
{
    this->year = year;
}

void Date::read()
{
    while (true) {

        std::cin >> this->day;
        std::cin >> this->month;
        std::cin >> this->year;

        if (this->valid(this->day, this->month, this->year)) break;
        else std::cout << "Invalid date, try again: \n";
    }
}

void Date::print() const
{
    std::cout << this->day << " " << this->month << " " << this->year;
}
