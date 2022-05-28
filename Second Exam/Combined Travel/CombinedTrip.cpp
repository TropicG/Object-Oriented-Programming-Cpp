#include "CombinedTrip.h"

void CombinedTrip::aloc(const int& size)
{
    this->destinations = new (std::nothrow) char[size + 1];
}

void CombinedTrip::del()
{
    delete[] this->destinations;
}

int CombinedTrip::getLength(const char* str) const
{
    int count = 0;

    while (*str != '\0') {
        count++;
        str++;
    }

    return count;
}

void CombinedTrip::cpy(const char* destinations)
{
    int size = this->getLength(flightNumber);
    this->del();
    this->aloc(size);

    for (int i = 0; i < size; ++i) {
        this->destinations[i] = destinations[i];
    }
    this->destinations[size] = '\0';
}

CombinedTrip::CombinedTrip() : AirTravel(), CarTravel(), destinations(nullptr), freeTime(0)
{
}

CombinedTrip::CombinedTrip(const char* destinations, const int& freeTime, const char* flightNumber, const int& durationPlane, const char* carNumber, const float& distance, const int& durationCar)
    : AirTravel(flightNumber, durationPlane), CarTravel(carNumber, distance, durationCar)
{
    this->setDestinations(destinations);
    this->setFreeTime(freeTime);
}

CombinedTrip::CombinedTrip(const CombinedTrip& other)
    : AirTravel(other), CarTravel(other)
{
    this->setDestinations(other.getDestinations());
    this->setFreeTime(other.getFreeTime());
}

CombinedTrip& CombinedTrip::operator=(const CombinedTrip& other)
{
    if (this != &other) {

        AirTravel::operator=(other);
        CarTravel::operator=(other);

        this->del();
        this->setDestinations(other.getDestinations());
        this->setFreeTime(other.getFreeTime());
    }

    return *this;
}

CombinedTrip::~CombinedTrip()
{
    this->del();
}

const char* CombinedTrip::getDestinations() const
{
    return this->destinations;
}

int CombinedTrip::getFreeTime() const
{
    return this->freeTime;
}

int CombinedTrip::getWholeDuration() const
{
    return AirTravel::getDuration() + CarTravel::getDuration() + this->freeTime;
}

void CombinedTrip::setDestinations(const char* destnations)
{
    this->cpy(destnations);
}

void CombinedTrip::setFreeTime(const int& freeTime)
{
    this->freeTime = freeTime;
}

void CombinedTrip::print() const
{

    AirTravel::print();
    CarTravel::print();

    std::cout << this->getDestinations() << " " << this->getFreeTime() << "\n";
}
