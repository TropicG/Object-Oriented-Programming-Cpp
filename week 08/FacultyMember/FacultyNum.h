#ifndef FACULTYMEMBER
#define FACULTYMEMBER
#include "Student.h"
#include "Lecurer.h"
class FacultyMember : public Student, public Lecurer {
public:
	FacultyMember();
	FacultyMember(const char* name, const unsigned& number, const double& salary);
	FacultyMember(const FacultyMember& other);

	void read();
	void print() const;

	friend std::ostream& operator<<(std::ostream& os, const FacultyMember& fac);
	friend std::istream& operator>>(std::istream& is, FacultyMember& fac);
};
#endif

