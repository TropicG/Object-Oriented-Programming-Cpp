#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "Student.h"
#include <stdexcept>
#include <algorithm>

class University {
private:
    Student* students = nullptr;
    int size = 0;
    int index = 0;

private:
    void initialize(const int& size);
    void clear();

    bool inside(const Student& other) const;

    Student* getStudent(const int& fn) const;

public:
    University();
    University(const int& size);
    University(const University& other);
    University& operator=(const University& other);
    ~University();

    void sort(bool(*cmp)(const Student&, const Student&));
    void filter(bool(*pred)(const Student&));

    University& operator+=(const Student& student);
    University& operator-=(const int& fn);
    Student operator[](const int& index) const;

    int getSize() const;

    void setSize(const int& size);

    friend std::ostream& operator<<(std::ostream& os, const University& uni);
    friend std::istream& operator>>(std::istream& is, University& uni);
};
#endif
