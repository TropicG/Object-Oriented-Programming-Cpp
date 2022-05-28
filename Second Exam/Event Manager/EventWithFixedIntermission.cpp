#include "EventWithFixedIntermission.h"

EventWithFixedIntermission::EventWithFixedIntermission() : Event(), antract(0)
{
}

EventWithFixedIntermission::EventWithFixedIntermission(const Hour& begin, const Hour& end, const int& antract)
{

	Hour lenght(MAX_EVENT_FIXED_INTERMISSION_HOUR, MAX_EVENT_FIXED_INTERMISSION_MINUTE);
	Hour diff = end - begin;

	if (diff >= lenght) {
		std::cout << "The length of the simple event must be maximum 4 hours";
		return;
	}

	this->setBegin(begin);
	this->setEnd(end);

	if (antract > MAX_INTERMISSION) {
		this->setAntract(MAX_INTERMISSION);
	}
	else {
		this->setAntract(antract);
	}
}

Hour EventWithFixedIntermission::getLength() const
{
	return this->end - this->begin;
}

void EventWithFixedIntermission::setAntract(const int& antract)
{
	this->antract = antract;
}

int EventWithFixedIntermission::getAntract() const
{
	return this->antract;
}
