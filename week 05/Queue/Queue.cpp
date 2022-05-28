#include "Queue.h"

Queue::Queue() : capacity(max)
{
}

Queue::Queue(const int& size) : capacity(size)
{
}

Queue& Queue::operator=(const Queue& other)
{
	if (this != &other) {
		for (int i = 0; i < other.getSize(); ++i) {
			this->tickets.push_back(new (std::nothrow) Ticket(*other.tickets[i]));
		}
		this->capacity = other.capacity;
	}

	return *this;
}

Queue::~Queue()
{
	for (int i = 0; i < this->getSize(); ++i) {
		delete this->tickets[i];
	}
}

void Queue::addTicket(const Ticket& tick)
{
	if (this->getSize() == capacity) {
		throw std::overflow_error("There is no more space for this ticket");
	}

	this->tickets.push_back(new (std::nothrow) Ticket(tick));
}

Ticket Queue::operator[](const unsigned& id)
{
	for (int i = 0; i < this->getSize(); ++i) {
		if (tickets[i]->getId() == id) {
			return *tickets[i];
		}
	}

	throw std::invalid_argument("There is no such ticket with this id");
}

Ticket Queue::next()
{
	Ticket temp = *this->tickets[getSize() - 1];
	
	this->tickets.pop_back();

	return temp;
}

bool Queue::empty() const
{
	return this->getSize() == 0;
}

int Queue::getSize() const
{
	return this->tickets.size();
}
