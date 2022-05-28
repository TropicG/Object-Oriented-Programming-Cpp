#ifndef VIRUS
#define VIRUS
#include <iostream>
#include <cstring>

const int nameMax = 65;

class Virus {
private:
	char* name = nullptr;
	unsigned servility = 0;

public:
	Virus();
	Virus(const char* name, const unsigned& servility);
	Virus(const Virus& other);
	Virus& operator=(const Virus& other);
	~Virus();

	bool operator==(const Virus& other) const;

	bool operator>(const Virus& other) const;
	bool operator>=(const Virus& other) const;

	bool operator<(const Virus& other) const;
	bool operator<=(const Virus& other) const;

	const char* getName() const;
	unsigned getServility() const;

	void setName(const char* name);
	void setServility(const unsigned& servility);

	friend std::ostream& operator<<(std::ostream& os, const Virus& virus);
	friend std::istream& operator>>(std::istream& is, Virus& virus);
};
#endif
