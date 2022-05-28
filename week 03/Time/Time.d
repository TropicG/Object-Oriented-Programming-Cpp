#ifndef TIME_H
#define TIME_H
#include <iostream>

class Time
{
private:
	unsigned hour = 0, minute = 0;
public:
	Time();
	Time(const int& hour, const int& minute);
	Time(const Time& other);

	void toNYC();
	void toSofia();
	void toMoscow();

	int getHours() const;
	int getMinutes() const;

	void setHour(const int& hour);
	void setMinute(const int& minutes);

	void print() const;

};
#endif
