#ifndef STUDENT
#define STUDENT
#include "Person.h"

class Student : virtual public Person {
protected:
	unsigned number = 0;

public:
	Student();
	Student(const char* name, const unsigned& number);
	Student(const Student& other);

	unsigned getNumber() const;

	void setNumber(const unsigned& num);

	void read();
	void print() const;
};
#endif
