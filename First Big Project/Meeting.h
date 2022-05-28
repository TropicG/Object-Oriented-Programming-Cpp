#ifndef MEETING_H
#define MEETING_H
#include "Date.h"
#include "Hour.h"
#include "String.h"

class Meeting {
private:
	String name;
	String comm;
	Date date;
	Hour start;
	Hour end;

public:
	Meeting();
	Meeting(const String& name, const String& comm, const Date& date, const Hour& start, const Hour& end);
	Meeting(const Meeting& other);
	Meeting& operator=(const Meeting& other);
	~Meeting();

	bool operator==(const Meeting& other) const;

	bool operator>(const Meeting& other) const;

	bool isBetweenDates(const Date& start, const Date& end) const;
	bool isNotOverlapping(const Meeting& other) const;

	const String& getName() const;
	const String& getCommentar() const;
	const Date& getDate() const;
	const Hour& getStart() const;
	const Hour& getEnd() const;

	void setName(const String& name);
	void setCommentar(const String& comm);
	void setDate(const Date& date);
	void setStart(const Hour& start);
	void setEnd(const Hour& end);

	void read();
	void print() const;
};
#endif