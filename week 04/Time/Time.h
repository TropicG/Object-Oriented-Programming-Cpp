#ifndef TIME
#define TIME
#include <iostream>
#include <cmath>

class Time {
private:
	unsigned hour = 0;
	unsigned minute = 0;

public:
	Time();
	Time(const int& hour, const int& minute);
	Time& operator=(const Time& other);

	bool operator==(const Time& other) const;
	bool operator>(const Time& other) const;
	bool operator<(const Time& other) const;

	Time operator+(const Time& other);
	Time operator+(const int& hours);

	Time operator-(const Time& other);
	Time operator-(const int& hours);

	Time& operator+=(const Time& other);
	Time& operator+=(const int& hour);

	Time& operator-=(const Time& other);
	Time& operator-=(const int& hour);

	unsigned getHour() const;
	unsigned getMinute() const;

	void setHour(const int& hour);
	void setMinute(const int& minute);

	friend std::istream& operator>> (std::istream& is, Time& time);
	friend std::ostream& operator<< (std::ostream& os, Time& time);

};
#endif