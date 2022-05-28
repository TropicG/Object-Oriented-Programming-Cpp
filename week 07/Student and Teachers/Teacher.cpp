#include "Teacher.h"

bool Teacher::inside(const Course& course) const
{
    for (int i = 0; i < this->teaching.size(); ++i) {
        if (*this->teaching[i] == course) {
            return true;
        }
    }
    return false;
}

Teacher::Teacher() : Human()
{
}

Teacher::Teacher(std::string& name, std::string& family, const unsigned& age, const unsigned& expirience) :
    Human(name.c_str(), family.c_str(), age)
{
    this->setExprieince(expirience);
}

Teacher::Teacher(const Teacher& other) : Human(other)
{
}

Teacher::~Teacher()
{
    for (int i = 0; i < this->teaching.size(); ++i) {
        delete this->teaching[i];
    }
}

void Teacher::addCourse(const Course& course)
{
    if (inside(course)) {
        throw CourseTeaching();
    }

    this->teaching.push_back(new Course(course));
}

void Teacher::removeCourse(const Course& course)
{
    if (!inside(course)) {
        throw CourseNotTeaching();
    }

    for (int i = 0; i < this->teaching.size(); ++i) {
        if (*this->teaching[i] == course) {
            this->teaching.erase(this->teaching.begin() + i);
        }
    }
}

Course& Teacher::operator[](const unsigned& index) const
{
    return *this->teaching[index];
}

Course Teacher::operator[](const unsigned& index)
{
    return *this->teaching[index];
}

unsigned Teacher::getExpirience() const
{
    return this->expirience;
}

void Teacher::setExprieince(const unsigned& expirience)
{
    this->expirience = expirience;
}
