#include "Day.h"

void Day::del()
{
	delete[] this->meet;
}

void Day::inOrder() 
{
	//if one meeting is earlier we swap those meetings
	for (int i = 0; i < this->size - 1; ++i) {
		if (this->meet[i] > this->meet[this->size - 1]) this->swap(this->meet[i], this->meet[this->size - 1]);
	}
}

bool Day::isInside(const Meeting& meet) const
{
	//cehcks all meetings are they equal to meet
	for (int i = 0; i < size; ++i) if (this->meet[i] == meet) return true;

	return false;
}

bool Day::isOverlapping(const Meeting& meet) const
{
	//if a meeting is overlapping with another we return true
	for (int i = 0; i < size; ++i) {
		if (!meet.isNotOverlapping(this->meet[i]) && this->meet[i].getDate() == meet.getDate()) return true;
	}

	return false;
}

int Day::getLocOfMeeting(const Meeting& meet) const
{
	//if we found the date of the meeting we return the location of the meeting
	for (int i = 0; i < this->size; ++i) {
		if (this->meet[i] == meet) return i;
	}
}

void Day::swap(Meeting& that, Meeting& other)
{
	Meeting temp;

	temp = that;
	that = other;
	other = temp;
}

void Day::aloc()
{
	this->meet = new Meeting[MAX_MEETINGS];
	if (!meet) { std::cout << "Failed memory allocaiton! \n"; return; }
}

Day::Day() : meet(nullptr), size(0)
{
	this->del();
	this->aloc();
}

Day::Day(const Day& other)
{
	this->del();
	this->aloc();

	for (int i = 0; i < other.size; ++i) {
		this->meet[i] = other.meet[i];
	}

	this->size = other.size;
}

Day& Day::operator=(const Day& other)
{
	if (this != &other) {

		this->del();
		this->aloc();

		for (int i = 0; i < other.size; ++i) {
			this->meet[i] = other.meet[i];
		}
		this->size = other.size;
	}

	return *this;
}

Day::~Day()
{
	this->del();
}

void Day::addMeeting(const Meeting& meet)
{
	if (this->size == MAX_MEETINGS) { std::cout << "You cant have more meetings on this day"; return; }

	if (this->isInside(meet)) { std::cout << "This meeting is already added on that day"; return; }

	if (this->isOverlapping(meet)) { std::cout << "This meeting overlaps another meeting, try again"; return; }

	//we place the meeting in this day and we place it in the right position
	this->meet[this->size++] = meet;
	this->inOrder();

}

void Day::removeMeeting(const Meeting& meet)
{
	if (isEmpty()) { std::cout << "This day is free, you cant remove from it"; return; }

	if (!isInside(meet)) { std::cout << "This meeting is not on that day"; return; }

	//gets the location of the meeting
	int loc = getLocOfMeeting(meet);
	
	//from we move down the next meetings with 1 position from loc index
	for (int i = loc; i < this->size - 1; ++i) {
		this->meet[i] = this->meet[i + 1];
	}
	this->size--;
}

bool Day::isEmpty() const
{
	return this->size == 0;
}

void Day::search(const String& str) const
{
	for (int i = 0; i < this->size; ++i) {
		if (meet[i].getName() == str || meet[i].getCommentar() == str) meet[i].print();
	}
}


Hour Day::totalBusyTime() const
{
	Hour total(0, 0);
	Hour diff(0, 0);

	//gets the total busy time for this day
	for (int i = 0; i < this->size; ++i) {
		diff = (this->meet[i].getEnd() - this->meet[i].getStart());
		total += diff;
	}

	return total;
}

bool Day::canFindFreeTime(const Hour& start, const Hour& end, const Hour& length)
{
	//checks can we have time between the start period and the start of the first meeting for the day
	if (this->meet[this->size].getStart() - start >= length) return true;

	//checks is the difference between the start and the end of two meetings enought to place a new meeting
	for (int i = 0; i < this->size - 1; ++i) {

		Hour start = this->meet[i + 1].getStart();
		Hour end = this->meet[i].getEnd();

		if (start - end >= length) return true;
	}

	//check can we have time between the end period and the end of the last meeting for the day
	if (end - this->meet[this->size - 1].getEnd() >= length) return true;
	
	return false;
}

Date Day::getDate() const
{
	return this->meet[0].getDate();
}

void Day::print() const
{
	for (int i = 0; i < this->size; ++i) {
		this->meet[i].print();
	}
}
