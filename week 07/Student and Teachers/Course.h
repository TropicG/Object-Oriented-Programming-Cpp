#ifndef COURSE
#define COURSE
#include <string>

class Course {
private:
	std::string name;

public:
	Course();
	Course(const char* name);
	Course(const Course& other);

	bool operator==(const Course& other) const;

	const std::string getName() const;

	void setName(const char* name);
};
#endif 
