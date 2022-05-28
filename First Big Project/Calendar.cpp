#include "Calendar.h"

int Calendar::getLocOfDate(const Date& date) const
{
    //returns the index of the met date
    for (int i = 0; i < this->size; ++i) {
        if (this->days[i].getDate() == date) return i;
    }

    return -1;
}

void Calendar::aloc(const int& cap)
{
    this->days = new Day[cap];
}

void Calendar::del()
{
    delete[] this->days;
}

Calendar::Calendar()
{
    this->cap = MAX_DAYS;
    this->del();
    this->aloc(this->cap);
    if (!this->days) { std::cout << "Cant allocate memory! \n\n"; return; }
}

Calendar::Calendar(const int& capacity)
{
    if (capacity > MAX_DAYS) this->cap = MAX_DAYS;
    else this->cap = capacity;

    this->del();
    this->aloc(capacity);
}

Calendar::~Calendar()
{
    this->del();
}

void Calendar::addMeeting(const Meeting& meeting)
{
    if (this->size == this->cap) { std::cout << "You cant put more meetings on the calendar \n\n"; return; }

    int loc = this->getLocOfDate(meeting.getDate());


    //if we add a day this day stays in the Calander even after all meetings for it were removed
    
    //this way if we found a loc of the date we put the meeting on this index
    if (loc >= 0) this->days[loc].addMeeting(meeting);

    //else we create a new Day and add to it meeting 
    else {

        Day newDay;
        newDay.addMeeting(meeting);

        //then adding it to calendar
        this->days[this->size++] = newDay;
    }
}

bool Calendar::isEmpty() const
{
    return this->size == 0;
}

void Calendar::remMeeting(const Meeting& meeting)
{
    if (this->isEmpty()) { std::cout << "The calendar is empty! \n\n"; return; }

    //gets the location of the date
    int loc = getLocOfDate(meeting.getDate());

    //if there is no such index we return error
    if (loc < 0) { std::cout << "There is no such meeting in the calendar! \n\n"; return; }

    this->days->removeMeeting(meeting);
}

void Calendar::showSchedule(const Date& date) const
{
    int loc = this->getLocOfDate(date);
    if (loc < 0) Date().print();

    this->days[loc].print();
}

Date Calendar::findFreeTime(const Date& startWeek, const Date& endWeek, const Hour& startPeriod, const Hour& endPeriod, const Hour& period)
{
    for (int i = 0; i < this->size; ++i) {

        Date currentDay = this->days[i].getDate();

        if (currentDay >= startWeek && currentDay <= endWeek
            && this->days[i].canFindFreeTime(startPeriod, endPeriod, period)) return currentDay;
    }

    return Date(0, 0, 0);
}

void Calendar::search(const String& str) const
{
    for (int i = 0; i < this->size; ++i) {
        this->days[i].search(str);
    }
}


