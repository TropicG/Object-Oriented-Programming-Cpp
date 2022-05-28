#include "University.h"

University::University() : students(nullptr), size(0), index(0) {
}

University::University(const int& size) {
    this->setSize(size);
    this->initialize(size);
}

University::University(const University &other) {

    this->size = other.size;
    this->initialize(this->size);
    for(this->index = 0 ; this->index < size; ++this->index){
        this->students[this->index] = other[this->index];
    }

}

University &University::operator=(const University &other) {

    if(this != &other){

        this->size = other.size;

        clear();
        this->initialize(size);

        for(this->index = 0 ; this->index < size; ++this->index){
            this->students[this->index] = other[this->index];
        }
    }

    return *this;
}

University::~University() {
    void clear();
}

void University::sort(bool (*cmp)(const Student &, const Student &)) {

}

void University::filter(bool (*pred)(const Student &)) {

}

University &University::operator+=(const Student &student) {

    if(this->size - this->index == 1){
        throw std::overflow_error("There is no more space in the university");
    }

    if(inside(student)){
        throw std::invalid_argument("This student is already in the university");
    }

    this->students[index++] = student;
}

University &University::operator-=(const int &fn) {

    if(this->size == 0){
        throw std::invalid_argument("The university is empty");
    }

    Student* temp = this->getStudent(fn);
    if(temp == nullptr){
        throw std::invalid_argument("The student is not in the list");
    }

    for(int i = 0; i < size; ++i){
        if(*temp == students[i]){
            std::swap(students[i], students[this->index - 1]);
            break;
        }
    }
    this->index--;

    return *this;
}

Student University::operator[](const int &index) const {
    return this->students[index];
}

int University::getSize() const {
    return this->size;
}

void University::setSize(const int &size) {
    this->size = size;
}

void University::initialize(const int &size) {
    this->students = new Student[size];
}

void University::clear() {
    delete[] this->students;
}

bool University::inside(const Student &other) const {
    return false;
}

Student* University::getStudent(const int &fn) const {

    for(int i=0; i < this->size; ++i){
        if(fn == students[i].getFacNum()){
            return &students[i];
        }
    }

    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const University &uni) {

    os << uni.size << std::endl;
    for(int i=0;i<uni.size;++i){
        os << uni[i];
    }

    return os;
}

std::istream &operator>>(std::istream &is, University &uni) {

    int size = 0;
    is >> size;

    uni.setSize(size);
    uni.initialize(size);

    for(int i=0;i<size;++i){

        Student temp;
        is >> temp;
        uni.students[i] = temp;
    }

    return is;
}
