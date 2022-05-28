#include "EventManager.h"

void EventManager::aloc(const int& cap)
{
    this->events = new (std::nothrow) Event *[cap];
}

void EventManager::del()
{
    for (int i = 0; i < this->size; ++i) {
        delete this->events[i];
    }

    delete[] this->events;
}

void EventManager::copy(const EventManager& other)
{

    this->del();
    this->size = 0;

    this->aloc(other.size);

    for (int i = 0; i < other.size;++i) {
    
    
        SimpleEvent* smP = dynamic_cast<SimpleEvent*>(other.events[i]);
        EventWithFixedIntermission* efiP = dynamic_cast<EventWithFixedIntermission*>(other.events[i]);
        EventWithIntermission* ewiP = dynamic_cast<EventWithIntermission*>(other.events[i]);

        if (smP) {
            this->events[this->size++] = new SimpleEvent(*smP);
        }
        if (efiP) {
            this->events[this->size++] = new EventWithFixedIntermission(*efiP);
        }
        if (ewiP) {
            this->events[this->size++] = new EventWithIntermission(*ewiP);
        }

    
    }

}

EventManager::EventManager()
{
    this->aloc(MAX_CAPACITY);
}

EventManager::EventManager(const int& cap)
{
    if (cap > MAX_CAPACITY) {
        this->aloc(MAX_CAPACITY);
    }
    else {
        this->aloc(cap);
    }
}

EventManager::EventManager(const EventManager& other)
{
    this->copy(other);
}

EventManager::~EventManager()
{
}

bool EventManager::add(Event* event)
{
    if (this->size == MAX_CAPACITY) return false;

    SimpleEvent* smP = dynamic_cast<SimpleEvent*>(event);
    EventWithFixedIntermission* efiP = dynamic_cast<EventWithFixedIntermission*>(event);
    EventWithIntermission* ewiP = dynamic_cast<EventWithIntermission*>(event);

    if (smP) {
        this->events[this->size++] = new SimpleEvent(*smP);
    }
    if (efiP) {
        this->events[this->size++] = new EventWithFixedIntermission(*efiP);
    }
    if (ewiP) {
        this->events[this->size++] = new EventWithIntermission(*ewiP);
    }

    return true;
}
