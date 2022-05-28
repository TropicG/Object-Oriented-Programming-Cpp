#ifndef STUDENT
#define STUDENT
#include "Human.h"
#include "Course.h"
#include <vector>
#include "exception.h"

class Student : public Human {
private:
	unsigned facultyNum = 0;
	std::string bach;
	std::vector<Course*> attending;

private:
	bool inside(const Course& course) const;

public:
	Student();
	Student(std::string name, std::string family, const unsigned& age, const unsigned& facultyNum, std::string bach);
	Student(const Student& other);
	~Student();

	void addCourse(const Course& course);
	void removeCourse(const Course& course);

	Course& operator[](const unsigned& index) const;
	Course operator[](const unsigned& index);
	unsigned getFaculty() const;
	const std::string getBachelor() const;

	void setFaculty(const unsigned& fac);
	void setBachelor(const std::string& bach);
};
#endif

