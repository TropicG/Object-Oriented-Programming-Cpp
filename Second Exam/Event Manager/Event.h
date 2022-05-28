#ifndef EVENT_H
#define EVENT_H
#include "Hour.h"

#include <iostream>

class Event {
protected:
	Hour begin;
	Hour end;

public:
	Event();
	Event(const Hour& begin, const Hour& end);

	Hour getBegin() const;
	Hour getEnd() const;

	virtual Hour getLength() const = 0;

	void setBegin(const Hour& begin);
	void setEnd(const Hour& end);
};
#endif