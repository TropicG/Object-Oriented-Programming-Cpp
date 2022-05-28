#ifndef HOUR_H
#define HOUR_H
#include <iostream>
#include <fstream>

class Hour {
private:
	int hour = 0;
	int minute = 0;

private:

	//checks are the arguments valid for Hour object
	bool valid(const int& hour, const int& minute) const;

public:
	Hour();
	Hour(const int& hour, const int& minute);
	Hour(const Hour& other);
	Hour& operator=(const Hour& other);

	//returns the difference between two hours
	//keep in mind that the code is used only when we subtact smaller hour from bigger hour
	Hour operator-(const Hour& other) const;

	//adding another hour
	//this operator is used when we calculate the total busy time for a day
	Hour& operator+=(const Hour& other);

	//checks are the two hours equal
	bool operator==(const Hour& other) const;
	
	//operators to see which hour is further in time
	bool operator>=(const Hour& other) const;
	bool operator<=(const Hour& other) const;

	bool operator>(const Hour& other) const;
	bool operator<(const Hour& other) const;

	//getters
	int getHour() const;
	int getMinute() const;

	//setters
	void setHour(const int& hour);
	void setMinute(const int& minute);

	//reading from the console and printring to the console
	void read();
	void print() const;
};
#endif

