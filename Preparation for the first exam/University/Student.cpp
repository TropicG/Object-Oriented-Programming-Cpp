#include "Student.h"

void Student::clearName() {
    delete[] this->name;
}

Student::Student() : name(nullptr), facNum(0), group(0), avarageScore(0) {

}

std::istream &operator>>(std::istream &is, Student &student) {

    char name[MAX_NAME];
    is.getline(name, MAX_NAME ,'|');
    is.ignore();
    student.setName(name);

    is >> student.facNum >> student.group >> student.avarageScore;

    return is;
}

void Student::setName(const char *name) {
    this->clearName();
    int size = strlen(name);
    this->name = new char[size + 1];
    strcpy(this->name,name);
}

std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << student.getName() << "|" << student.facNum << " " << student.group << " " << student.avarageScore << std::endl;

    return os;
}

void Student::setFacNum(const int &facNum) {
    this->facNum = facNum;
}

void Student::setGroup(const int &group) {
    this->group = group;
}

void Student::setScore(const double &score) {
    this->avarageScore = score;
}

double Student::getAveScore() const {
    return this->avarageScore;
}

int Student::getGroup() const {
    return this->group;
}

int Student::getFacNum() const {
    return this->facNum;
}

const char *Student::getName() const {
    return this->name;
}

bool Student::operator==(const Student &other) const {

    return this->facNum == other.facNum;
}

bool Student::operator<(const Student &other) const {

    bool bigger = this->avarageScore < other.avarageScore;

    if(!bigger){
        return this->facNum < other.facNum;
    }

    return bigger;
}

Student::~Student() {
    this->clearName();
}

Student &Student::operator=(const Student &other) {

    if(this != &other){
        this->setName(other.name);
        this->setFacNum(other.facNum);
        this->setGroup(other.group);
        this->setScore(other.avarageScore);
    }

    return *this;
}

Student::Student(const Student &other) {

    this->setName(other.name);
    this->setFacNum(other.facNum);
    this->setGroup(other.group);
    this->setScore(other.avarageScore);
}

Student::Student(const char *name, const int &facNum, const int &group, const double &score) {

    this->setName(name);
    this->setFacNum(facNum);
    this->setGroup(group);
    this->setScore(score);
}

void Student::read() {

    char name[MAX_NAME];
    std::cout << "Enter the name of the student: ";
    if(std::cin.peek() == '\n') std::cin.ignore();
    std::cin.getline(name, MAX_NAME, '\n');
    bool failed = std::cin.fail();
    if (failed) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    this->setName(name);

    std::cout << "Enter the group of the student: ";
    std::cin >> this->group;
    while(std::cin.fail() || group < 0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        std::cout << "Invalid argument, please try again: ";
        std::cin >> this->group;
    }

    std::cout << "Enter the faculty number of the student: ";
    std::cin >> this->facNum;
    while(std::cin.fail() || this->facNum < 0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        std::cout << "Invalid argument, please try again: ";
        std::cin >> this->facNum;
    }

    std::cout << "Enter the score of the student: ";
    std::cin >> this->avarageScore;
    while(std::cin.fail() || this->avarageScore < 0.0 || this->avarageScore > 6.0){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        std::cout << "Invalid argument, please try again: ";
        std::cin >> this->avarageScore;
    }
}

void Student::print() const {

    std::cout << "Name: " << this->name <<" Group: " << this->group;
    std::cout << " FacultyNumber: " << this->facNum << " Score: " << this->avarageScore << std::endl;
}
