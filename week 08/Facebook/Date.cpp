#include "Date.h"

bool Date::valid(const unsigned& year, const unsigned& month, const unsigned& day) const
{
    if(month == 2 || month == 4 || month == 6 || month == 9 || month == 11 && day == 31){
        return false;
    }

    bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    if (leap && month == 2 && day > 28) {
        return false;
    }

    return true;
}

Date::Date()
{
}

Date::Date(const unsigned& year, const unsigned& month, const unsigned& day)
{
    this->setYear(year);
    this->setMonth(month);
    this->setDay(day);
}

Date::Date(const Date& other)
{
    this->setYear(other.getYear());
    this->setMonth(other.getMonth());
    this->setDay(other.getDay());
}

Date& Date::operator=(const Date& other)
{
    if (this != &other) {

        this->setYear(other.getYear());
        this->setMonth(other.getMonth());
        this->setDay(other.getDay());
    }

    return *this;
}

unsigned Date::getYear() const
{
    return this->year;
}

unsigned Date::getMonth() const
{
    return this->month;
}

unsigned Date::getDay() const
{
    return this->day;
}

void Date::setYear(const unsigned& year)
{
    this->year = year;
}

void Date::setMonth(const unsigned& month)
{
    this->month = month;
}

void Date::setDay(const unsigned& day)
{
    this->day = day;
}

void Date::print() const
{
    std::cout << this->getYear() << " " << this->getMonth() << " " << this->getDay() << std::endl;
}

void Date::read()
{
    unsigned year = 0, month = 0, day = 0;
    std::cout << "Enter the day of registration: ";
    std::cin >> day >> month >> year;
    while (std::cin.fail() || month == 0 || month > 12 || day == 0 || day > 31) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid argument, plase try again: ";
        std::cin >> year >> month >> day;
    }

    if (!valid(year, month, day)) {
        throw InvalidDate();
    }

    this->setYear(year);
    this->setMonth(month);
    this->setDay(day);
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.getDay() << " " << date.getMonth() << " " << date.getYear();

    return os;
}

std::istream& operator>>(std::istream& is, Date& date)
{
    is >> date.year >> date.month >> date.day;

    return is;
}
