#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
#include <limits>

const int MAX_NAME = 1024;

class Student {
private:
    char* name = nullptr;
    int facNum = 0;
    int group = 0;
    double avarageScore = 0;

private:
    void clearName();

public:
    Student();
    Student(const char* name, const int& facNum, const int& group, const double& score);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();

    bool operator<(const Student& other) const;
    bool operator==(const Student& other) const;

    const char* getName() const;
    int getFacNum() const;
    int getGroup() const;
    double getAveScore() const;

    void setName(const char* name);
    void setFacNum(const int& facNum);
    void setGroup(const int& group);
    void setScore(const double& score);

    void read();
    void print() const;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
};
#endif
