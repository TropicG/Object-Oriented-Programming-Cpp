#ifndef LECURER
#define LECURER
#include "Person.h"
class Lecurer : virtual public Person {
protected:
	double salary = 0;

public:
	Lecurer();
	Lecurer(const char* name, const double& salary);
	Lecurer(const Lecurer& other);

	double getSalary() const;

	void setSalary(const double& salary);

	void read();
	void print() const;
};
#endif
