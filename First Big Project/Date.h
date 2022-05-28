#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <fstream>

class Date {
private:
	int day = 0;
	int month = 0;
	int year = 0;

private:
	//checks is the date valid
	bool valid(const int& day, const int& month, const int& year) const;

public:
	Date();
	Date(const int& day, const int& month, const int& year);
	Date(const Date& other);
	Date& operator=(const Date& other);

	//operators for comparison
	bool operator==(const Date& other) const;
	bool operator!=(const Date& other) const;

	bool operator>=(const Date& other) const;
	bool operator<=(const Date& other) const;

	bool operator>(const Date& other) const;
	bool operator<(const Date& other) const;

	//getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	//setters
	void setDay(const int& day);
	void setMonth(const int& month);
	void setYear(const int& year);

	//reading and printing from the console
	void read();
	void print() const;
};
#endif