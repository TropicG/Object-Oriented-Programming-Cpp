#ifndef CALENDAR_H
#define CALENDAR_H

#include "Day.h"
#include <fstream>

const int MAX_DAYS = 366;

class Calendar {
private:
	Day* days = nullptr;
	int cap = 0;
	int size = 0;

private:
	int getLocOfDate(const Date& date) const;

	void aloc(const int& cap);
	void del();
	
public:
	Calendar();
	Calendar(const int& capacity);
	~Calendar();

	//adding meeting to the calendar
	void addMeeting(const Meeting& meeting);

	//removing meeting from the calendar
	void remMeeting(const Meeting& meeting);

	//checks is the calendar empty
	bool isEmpty() const;

	//shows the meetings in a chronological order in this day
	void showSchedule(const Date& date) const;

	//find free time in this period
	Date findFreeTime(const Date& startWeek, const Date& endWeek, const Hour& startPeriod, const Hour& endPeriod, const Hour& period);

	void search(const String& str) const;
};
#endif