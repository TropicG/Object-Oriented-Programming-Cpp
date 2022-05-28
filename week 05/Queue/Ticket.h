#ifndef TICKET
#define TICKET
#include <iostream>
#include <cstring>
#include <stdexcept>

const int nameSize = 65, phoneSize = 11;

class Ticket {
private:
	char* name = nullptr;
	char* phone = nullptr;
	unsigned id = 0;

private:
	bool validName(const char* name) const;
	bool validPhone(const char* phone) const;

public:
	Ticket();
	Ticket(const char* name, const char* phone, const int& id);
	Ticket(const Ticket& other);
	Ticket& operator=(const Ticket& other);
	~Ticket();

	bool operator==(const Ticket& other) const;

	const char* getName() const;
	const char* getPhone() const;
	unsigned getId() const;

	void setName(const char* name);
	void setPhone(const char* phone);
	void setID(const int& id);

	friend std::ostream& operator<<(std::ostream& os, const Ticket& other);
	friend std::istream& operator>>(std::istream& is, Ticket& other);
};
#endif
