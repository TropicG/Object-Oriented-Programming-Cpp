#include "FamilyCar.h"

FamilyCar::FamilyCar() : Car()
{
}

FamilyCar::FamilyCar(const double& maxSpeed, const double& currentSpeed, const double& price) :
    Car(maxSpeed, currentSpeed, price)
{
}

FamilyCar::FamilyCar(const FamilyCar& other)
{
    this->setCurrentSpeed(other.getCurrentSpeed());
    this->setMaxSpeed(other.getMaxSpeed());
    this->setPrice(other.getPrice());
}

FamilyCar& FamilyCar::operator=(const FamilyCar& other)
{
    if (this != &other) {

        this->setCurrentSpeed(other.getCurrentSpeed());
        this->setMaxSpeed(other.getMaxSpeed());
        this->setPrice(other.getPrice());
    }

    return *this;
}

void FamilyCar::startMovement()
{
    std::cout << "Starting the engine" << std::endl;
    this->setCurrentSpeed(10);
}

void FamilyCar::stopMovement()
{
    std::cout << "Stoping the engine" << std::endl;
    this->setCurrentSpeed(0);
    std::cout << "Current speed is " << this->getCurrentSpeed() << std::endl;
}

void FamilyCar::accelerate()
{
    std::cout << "Accelerating" << std::endl;
    if (this->currentSpeed + 25 > this->maxSpeed) {
        this->currentSpeed = this->maxSpeed;
    }
    else {
        this->currentSpeed += 25;
    }
    std::cout << "Current speed is " << this->getCurrentSpeed() << std::endl;
}

void FamilyCar::read()
{
    Car::read();
}

void FamilyCar::print()
{
    Car::print();
}
