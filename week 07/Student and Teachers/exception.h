#ifndef EXCEPTION
#define EXCEPTION
#include <iostream>

//exceptions for class Student
class CourseAdded : public std::exception {
public:
	const char* what() const throw() {
		return "This student is already attendind this course";
	}
};
class CourseNotAdded : public std::exception {
public:
	const char* what() const throw() {
		return "This student has not attented this course";
	}
};

//exceptions for class Teacher
class CourseTeaching : public std::exception {
public:
	const char* what() const throw() {
		return "This teacher is already teaching this course";
	}
};
class CourseNotTeaching : public std::exception {
public:
	const char* what() const throw() {
		return "This teacher is not teaching this course";
	}
};
#endif

