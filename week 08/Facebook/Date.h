#ifndef DATE
#define DATE
#include <iostream>
#include "exception.h"

class Date {
private:
	unsigned year = 0;
	unsigned month = 0;
	unsigned day = 0;

private:
	bool valid(const unsigned& year, const unsigned& month, const unsigned& day)const;

public:
	Date();
	Date(const unsigned& year, const unsigned& month, const unsigned& day);
	Date(const Date& other);
	Date& operator=(const Date& other);

	unsigned getYear() const;
	unsigned getMonth() const;
	unsigned getDay() const;

	void setYear(const unsigned& year);
	void setMonth(const unsigned& month);
	void setDay(const unsigned& day);

	void read();
	void print() const;

	friend std::ostream& operator<<(std::ostream& os, const Date& date);
	friend std::istream& operator>>(std::istream& is, Date& date);
};
#endif