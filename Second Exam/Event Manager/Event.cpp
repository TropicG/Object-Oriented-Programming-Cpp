#include "Event.h"

Event::Event() : begin(0,0), end(0,0)
{
}

Event::Event(const Hour& begin, const Hour& end)
{
    this->setBegin(begin);
    this->setEnd(end);
}

Hour Event::getBegin() const
{
    return this->begin;
}

Hour Event::getEnd() const
{
    return this->end;
}

void Event::setBegin(const Hour& begin)
{
    this->begin = begin;
}

void Event::setEnd(const Hour& end)
{
    this->end = end;
}
