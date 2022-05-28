#ifndef HUMAN
#define HUMAN
#include <iostream>
#include <string>

const int nameMax = 65;

class Human {
protected:
	std::string name;
	std::string family;
	unsigned age = 0;

public:
	Human();
	Human(const char* name, const char* family, const unsigned& age);
	Human(const Human& other);

	const std::string getName() const;
	const std::string getFamily() const;
	unsigned getAge() const;

	void setName(const char* name);
	void setFamily(const char* family);
	void setAge(const unsigned& age);

	void print() const;
	void read();
};
#endif