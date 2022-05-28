#include "AirTravel.h"

int AirTravel::getLength(const char* str) const {

    int count = 0;
    
    while (*str != '\0') {
        count++;
        str++;
    }

    return count;
}

AirTravel::AirTravel() : flightNumber(nullptr), duration(0)
{
}

void AirTravel::aloc(const int& size)
{
    this->flightNumber = new (std::nothrow) char[size + 1];
}

AirTravel::AirTravel(const char* flightNumber, const int& duration) 
{
    this->setDuration(duration);
    this->setFlightNumber(flightNumber);
}

void AirTravel::del()
{
    delete[] this->flightNumber;
}

AirTravel::AirTravel(const AirTravel& other)
{
    this->setFlightNumber(other.getFlightNumber());
    this->setDuration(other.getDuration());
}

AirTravel& AirTravel::operator=(const AirTravel& other)
{
    if (this != &other) {

        this->del();

        this->setFlightNumber(other.getFlightNumber());
        this->setDuration(other.getDuration());
    }

    return *this;
}

void AirTravel::cpy(const char* flightNumber)
{
    int size = this->getLength(flightNumber);
    this->del();
    this->aloc(size);

    for (int i = 0; i < size; ++i) {
        this->flightNumber[i] = flightNumber[i];
    }
    this->flightNumber[size] = '\0';
}

AirTravel::~AirTravel()
{
    this->del();
}

const char* AirTravel::getFlightNumber() const
{
    return this->flightNumber;
}

int AirTravel::getDuration() const
{
    return this->duration;
}

void AirTravel::setFlightNumber(const char* flightNumber)
{
    this->cpy(flightNumber);
}

void AirTravel::setDuration(const int& duration)
{
    this->duration = duration;
}

void AirTravel::print() const {

    std::cout << this->getFlightNumber() << " " << this->getDuration() << "\n";
}
