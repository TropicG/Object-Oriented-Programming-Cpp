#ifndef TEACHER
#define TEACHER
#include "Human.h"
#include "Course.h"
#include "exception.h"
#include <vector>

class Teacher : public Human {
private:
	unsigned expirience = 0;
	std::vector<Course*> teaching;

private:
	bool inside(const Course& course) const;

public:
	Teacher();
	Teacher(std::string& name, std::string& family, const unsigned& age, const unsigned& expirience);
	Teacher(const Teacher& other);
	~Teacher();

	void addCourse(const Course& course);
	void removeCourse(const Course& course);

	Course& operator[](const unsigned& index) const;
	Course operator[](const unsigned& index);
	unsigned getExpirience() const;

	void setExprieince(const unsigned& expirience);
};
#endif
