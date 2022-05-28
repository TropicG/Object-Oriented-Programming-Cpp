#include "EventWithIntermission.h"

EventWithIntermission::EventWithIntermission()
{
}

EventWithIntermission::EventWithIntermission(const Hour& begin, const Hour& end, const int& antract)
{
	Hour lenght(MAX_EVENT_INTERMISSION_HOUR, MAX_EVENT_INTERMISSION_MINUTE);
	Hour diff = end - begin;

	if (diff >= lenght) {
		std::cout << "The length of the simple event must be maximum 4 hours";
		return;
	}

	this->setBegin(begin);
	this->setEnd(end);

	if (antract < MIN_INTERMISSION_MINUTES || antract > MAX_INTERMISSION_MINUTES) {
		this->setAntract(MIN_INTERMISSION_MINUTES);
	}
	else {
		this->setAntract(antract);
	}

}

Hour EventWithIntermission::getLength() const
{
	return this->end - this->begin;
}

void EventWithIntermission::setAntract(const int& antract)
{
	this->setAntract(antract);
}

int EventWithIntermission::getAntract() const
{
	return this->antract;
}
