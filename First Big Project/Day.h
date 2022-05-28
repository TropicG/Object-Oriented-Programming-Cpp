#ifndef DAY_H
#define DAY_H

#include "Meeting.h"

//you can make total 30 minutes meetings for 1 day
const int MAX_MEETINGS = 64;

class Day {
private:
	Meeting* meet = nullptr;
	int size = 0;

private:
	//places a meeting at the right chronological order
	void inOrder();

	//checks is the meeting already inside 
	bool isInside(const Meeting& meet) const;

	//checks is a meeting overlapping all other meetings for the day
	bool isOverlapping(const Meeting& meet) const;

	//gets location of the meeting
	int getLocOfMeeting(const Meeting& meet) const;

	//swaps two meetings
	void swap(Meeting& that, Meeting& other);

	//allocating and deleting memory
	void aloc();
	void del();

public:
	Day();
	Day(const Day& other);
	Day& operator=(const Day& other);
	~Day();

	//adds meeting to the day
	void addMeeting(const Meeting& meet);

	//removes meeting from the day
	void removeMeeting(const Meeting& meet);
	
	//chekcs do we have free time for another meeting
	bool canFindFreeTime(const Hour& start, const Hour& end, const Hour& length);

	//gets all the busy time for the day
	Hour totalBusyTime() const;

	//searches for a meeting with a name or commantar for a str
	void search(const String& str) const;

	//is the day empty?
	bool isEmpty() const;

	//gets the day
	Date getDate() const;

	void print() const;
};
#endif