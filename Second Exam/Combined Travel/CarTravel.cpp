#include "CarTravel.h"

void CarTravel::aloc(const int& size)
{
    this->regNum = new (std::nothrow) char[size + 1];
}

void CarTravel::del()
{
    delete[] this->regNum;
}

int CarTravel::getLength(const char* str) const
{
    int count = 0;

    while (*str != '\0') {
        count++;
        str++;
    }

    return count;
}

void CarTravel::cpy(const char* regNumber)
{
    int size = this->getLength(regNum);
    this->del();
    this->aloc(size);

    for (int i = 0; i < size; ++i) {
        this->regNum[i] = regNumber[i];
    }
    this->regNum[size] = '\0';
}

CarTravel::CarTravel() : regNum(nullptr), distance(0), duration(0)
{
}

CarTravel::CarTravel(const char* regNum, const float& distance, const int& duration)
{
    this->setRegNum(regNum);
    this->setDistance(distance);
    this->setDuration(duration);
}

CarTravel::CarTravel(const CarTravel& other)
{
    this->setRegNum(other.getRegNum());
    this->setDistance(other.getDistance());
    this->setDuration(other.getDistance());
}

CarTravel& CarTravel::operator=(const CarTravel& other)
{
    if (this != &other) {

        this->del();

        this->setRegNum(other.getRegNum());
        this->setDistance(other.getDistance());
        this->setDuration(other.getDistance());
    }

    return *this;
}

CarTravel::~CarTravel()
{
    this->del();
}

const char* CarTravel::getRegNum() const
{
    return this->regNum;
}

float CarTravel::getDistance() const
{
    return this->distance;
}

int CarTravel::getDuration() const
{
    return this->duration;
}

void CarTravel::setRegNum(const char* regNum)
{
    this->cpy(regNum);
}

void CarTravel::setDuration(const int& duration)
{
    this->duration = duration;
}

void CarTravel::setDistance(const float& distance)
{
    this->distance = distance;
}

void CarTravel::print() const {

    std::cout << this->getRegNum() << " " << this->getDistance() << " " << this->getDuration() << "\n";
}
