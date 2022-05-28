#ifndef QUEUE
#define QUEUE
#include "Ticket.h"
#include <vector>

const int max = 128;

class Queue {
private:
	std::vector<Ticket*> tickets;
	unsigned capacity;
	
public:
	Queue();
	Queue(const int& size);
	Queue& operator=(const Queue& other);
	~Queue();

	void addTicket(const Ticket& tick);

	Ticket operator[](const unsigned& id);
	
	Ticket next();

	bool empty() const;
	int getSize() const;
};
#endif