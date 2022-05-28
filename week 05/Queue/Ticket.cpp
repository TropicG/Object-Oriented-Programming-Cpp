#include "Ticket.h"

bool Ticket::validName(const char* name) const
{
	int loc = 0, size = strlen(name);
	for (int i = 0; i < size; ++i) {
		if (name[i] == ' ') {
			loc = i;
		}
		if (!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z') && name[i] != ' ') {
			return false;
		}
	}
	
	return loc != 0 && loc != (size - 1);
}

bool Ticket::validPhone(const char* phone) const
{
	int size = strlen(phone);
	for (int i = 0; i < size; ++i) {
		if (phone[i] < '0' || phone[i] > '9') {
			return false;
		}
	}
	
	return size == (phoneSize - 1);
}

Ticket::Ticket() : name(nullptr), phone(nullptr), id(0)
{
}

Ticket::Ticket(const char* name, const char* phone, const int& id)
{
	this->setName(name);
	this->setPhone(phone);
	this->setID(id); 
}

Ticket::Ticket(const Ticket& other)
{
	this->setName(other.getName());
	this->setPhone(other.getPhone());
	this->setID(other.getId());
}

Ticket& Ticket::operator=(const Ticket& other)
{
	if (this != &other) {
		this->setName(other.getName());
		this->setPhone(other.getPhone());
		this->setID(other.getId());
	}

	return *this;
}

Ticket::~Ticket()
{
	delete[] this->name;
	delete[] this->phone;
}

bool Ticket::operator==(const Ticket& other) const
{
	return this->getId() == other.getId();
}

const char* Ticket::getName() const
{
	return this->name;
}

const char* Ticket::getPhone() const
{
	return this->phone;
}

unsigned Ticket::getId() const
{
	return this->id;
}

void Ticket::setName(const char* name)
{
	if (!this->validName(name)) throw std::invalid_argument("Invalid inputted name");

	delete[] this->name;
	this->name = new (std::nothrow) char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Ticket::setPhone(const char* phone)
{
	if (!this->validPhone(phone)) throw std::invalid_argument("Invalid inputted phone");

	delete[] this->phone;
	this->phone = new (std::nothrow) char[strlen(phone) + 1];
	strcpy_s(this->phone, strlen(phone) + 1, phone);
}

void Ticket::setID(const int& id)
{
	this->id = id;
}

std::ostream& operator<<(std::ostream& os, const Ticket& other)
{
	os << other.getName() << " " << other.getPhone() << " " << other.getId() << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Ticket& other)
{
	char temp[nameSize];
	std::cout << "Enter the name: ";
	if (is.peek() == '\n') is.ignore();
	is.getline(temp, nameSize, '\n');
	other.setName(temp);

	std::cout << "Enter the phone: ";
	is.getline(temp, phoneSize, '\n');
	other.setPhone(temp);

	int helper = 0;
	std::cout << "Enter the id: ";
	is >> helper;
	other.setID(helper);

	return is;
}
