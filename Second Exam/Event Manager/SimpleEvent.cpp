#include "SimpleEvent.h"

SimpleEvent::SimpleEvent() : Event()
{
}

SimpleEvent::SimpleEvent(const Hour& begin, const Hour& end)
{

	Hour lenght(MAX_EVENT_HOUR, MAX_EVENT_MINUTE);
	Hour diff = end - begin;

	if (diff >= lenght) {
		std::cout << "The length of the simple event must be maximum 2 hours";
		return;
	}

	this->setBegin(begin);
	this->setEnd(end);
}

SimpleEvent::SimpleEvent(const SimpleEvent& other)
{
	this->setBegin(other.getBegin());
	this->setEnd(other.getEnd());
}

Hour SimpleEvent::getLength() const
{
	return this->end - this->begin;
}
