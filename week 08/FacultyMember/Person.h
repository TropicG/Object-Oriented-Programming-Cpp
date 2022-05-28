#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>

const int nameMax = 33;

class Person {
protected:
	std::string name;

public:
	Person();
	Person(const char* name);
	Person(const Person& other);

	const std::string getName() const;

	void setName(const char* name);

	void read();
	void print() const;
};
#endif