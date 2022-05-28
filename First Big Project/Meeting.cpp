#include "Meeting.h"

Meeting::Meeting() : name(), comm(), date(), start(), end()
{
}

Meeting::Meeting(const String& name, const String& comm, const Date& date, const Hour& start, const Hour& end)
{
	this->setName(name);
	this->setCommentar(comm);
	this->setDate(date);
	this->setStart(start);
	this->setEnd(end);
}

Meeting::Meeting(const Meeting& other)
{
	this->setName(other.getName());
	this->setCommentar(other.getCommentar());
	this->setDate(other.getDate());
	this->setStart(other.getStart());
	this->setEnd(other.getEnd());
}

Meeting& Meeting::operator=(const Meeting& other)
{
	if (this != &other) {

		this->setName(other.getName());
		this->setCommentar(other.getCommentar());
		this->setDate(other.getDate());
		this->setStart(other.getStart());
		this->setEnd(other.getEnd());
	}

	return *this;
}

Meeting::~Meeting()
{
}

bool Meeting::operator==(const Meeting& other) const
{
	return this->name == other.name && this->comm == other.comm
		&& this->date == other.date && this->start == other.start
		&& this->end == other.end;
}

bool Meeting::operator>(const Meeting& other) const
{
	return this->date > other.date || (this->start > other.end);
}

bool Meeting::isBetweenDates(const Date& start, const Date& end) const
{
	return this->date >= start && this->date <= end;
}

bool Meeting::isNotOverlapping(const Meeting& other) const
{
	return this->end <= other.start || this->start >= other.end;
}

const String& Meeting::getName() const
{
	return this->name;
}

const String& Meeting::getCommentar() const
{
	return this->comm;
}

const Date& Meeting::getDate() const
{
	return this->date;
}

const Hour& Meeting::getStart() const
{
	return this->start;
}

const Hour& Meeting::getEnd() const
{
	return this->end;
}

void Meeting::setName(const String& name)
{
	this->name = name;
}

void Meeting::setCommentar(const String& comm)
{
	this->comm = comm;
}

void Meeting::setDate(const Date& date)
{
	this->date = date;
}

void Meeting::setStart(const Hour& start)
{
	this->start = start;
}

void Meeting::setEnd(const Hour& end)
{
	this->end = end;
}

void Meeting::read()
{
	std::cout << "Enter the name of the meeting: "; this->name.read();
	std::cout << "Enter commentar for it: "; this->comm.read();
	std::cout << "Enter the date of the meeting: "; this->date.read();
	std::cout << "Enter the starting hour: "; this->start.read();
	std::cout << "Enter the ending hour: "; this->end.read();
	std::cout << "\n";
}

void Meeting::print() const
{
	std::cout << "The name of the meeting: "; this->name.print(); std::cout << " ";
	std::cout << "with commentar: ";  this->comm.print(); std::cout << " ";
	std::cout << "on: ";  this->date.print(); std::cout << " ";
	std::cout << "at: "; this->start.print(); std::cout<< " ";
	std::cout << "till: "; this->end.print(); std::cout << std::endl;
}


