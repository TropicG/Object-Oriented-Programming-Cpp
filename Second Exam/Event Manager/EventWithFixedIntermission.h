#ifndef EVENT_WITH_FIXED_INTERMISSION_H
#define EVENT_WITH_FIXED_INTERMISSION_H
#include "Event.h"

const int MAX_INTERMISSION = 20;

const int MAX_EVENT_FIXED_INTERMISSION_HOUR = 4;
const int MAX_EVENT_FIXED_INTERMISSION_MINUTE = 0;

class EventWithFixedIntermission : public Event {
private:
	int antract;

public:
	EventWithFixedIntermission();
	EventWithFixedIntermission(const Hour& begin, const Hour& end, const int& antract);

	virtual Hour getLength() const override;

	void setAntract(const int& antract);

	int getAntract() const;
};
#endif