#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H
#include "SimpleEvent.h"
#include "EventWithFixedIntermission.h"
#include "EventWithIntermission.h"

const int MAX_CAPACITY = 128;

class EventManager {
private:
	Event** events;
	int size = 0;

private:
	void aloc(const int& cap);
	void del();

	void copy(const EventManager& other);

public:
	EventManager();
	EventManager(const int& cap);
	EventManager(const EventManager& other);
	~EventManager();

	bool add(Event* event);

};
#endif