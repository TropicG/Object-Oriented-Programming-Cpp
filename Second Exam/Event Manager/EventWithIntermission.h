#ifndef EVENT_WITH_INTERMISSION_H
#define EVENT_WITH_INTERMISSiON_H

#include "Event.h"

const int MAX_INTERMISSION_MINUTES = 60;
const int MIN_INTERMISSION_MINUTES = 30;

const int MAX_EVENT_INTERMISSION_HOUR = 4;
const int MAX_EVENT_INTERMISSION_MINUTE = 4;

class EventWithIntermission : public Event {
private:
	int antract;

public:
	EventWithIntermission();
	EventWithIntermission(const Hour& begin, const Hour& end, const int& antract);

	virtual Hour getLength() const override;

	void setAntract(const int& antract);

	int getAntract() const;
};
#endif