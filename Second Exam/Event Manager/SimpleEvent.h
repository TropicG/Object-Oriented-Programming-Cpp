#ifndef SIMPLE_EVENT_H
#define SIMPLE_EVENT_H

#include "Event.h"


const int MAX_EVENT_HOUR = 2;
const int MAX_EVENT_MINUTE = 0;

class SimpleEvent : public Event {
public:
	SimpleEvent();
	SimpleEvent(const Hour& begin, const Hour& end);
	SimpleEvent(const SimpleEvent& other);

	virtual Hour getLength() const override;
};
#endif