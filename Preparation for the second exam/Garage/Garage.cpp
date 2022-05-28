#include "Garage.h"

void Garage::aloc(const int& cap)
{
	this->cars = new Body * [cap];
}

void Garage::del()
{
	for (int i = 0; i < this->size; ++i) {
		delete this->cars[i];
	}
	delete[] this->cars;
}

Garage::Garage() : cap(MAX_CAP), size(0)
{
	this->aloc(cap);
}


Garage::Garage(const int& cap) : cap(cap), size(0)
{
	this->aloc(cap);
}

Garage::Garage(const Garage& other) : cap(other.cap), size(other.size)
{

	this->aloc(this->cap);

	for (int i = 0; i < this->size; ++i) {
		
		Car* carPtr = dynamic_cast<Car*>(other.cars[i]);
		Van* vanPtr = dynamic_cast<Van*>(other.cars[i]);
		Truck* truckPtr = dynamic_cast<Truck*>(other.cars[i]);

		
		if (carPtr) {
			this->cars[i] = new Car(*carPtr);
		}

		else if (vanPtr) {
			this->cars[i] = new Van(*vanPtr);
		}

		else  {
			this->cars[i] = new Truck(*truckPtr);
		}
	}
}

Garage& Garage::operator=(const Garage& other)
{
	if (this != &other) {

		this->aloc(this->cap);

		for (int i = 0; i < this->size; ++i) {

			Car* carPtr = dynamic_cast<Car*>(other.cars[i]);
			Van* vanPtr = dynamic_cast<Van*>(other.cars[i]);
			Truck* truckPtr = dynamic_cast<Truck*>(other.cars[i]);


			if (carPtr) {
				this->cars[i] = new Car(*carPtr);
			}

			else if (vanPtr) {
				this->cars[i] = new Van(*vanPtr);
			}

			else {
				this->cars[i] = new Truck(*truckPtr);
			}
		}

	}

	return *this;
}

Garage::~Garage()
{
	this->del();
}

void Garage::add(Body* vehicle)
{
	Car* carPtr = dynamic_cast<Car*>(vehicle);
	Van* vanPtr = dynamic_cast<Van*>(vehicle);
	Truck* truckPtr = dynamic_cast<Truck*>(vehicle);

	if (carPtr) {
		this->cars[this->size++] = new Car(*carPtr);
	}

	if (vanPtr) {
		this->cars[this->size++] = new Van(*vanPtr);
	}

	if (truckPtr) {
		this->cars[this->size++] = new Truck(*truckPtr);
	}
}

int Garage::getSuccsessfullOrderCount(const int& highway, const int& normal, const int& bad, const int& time)
{
	int count = 0;

	for (int i = 0; i < this->size; ++i) {

		if (this->cars[i]->travelTime(highway, normal, bad) <= time) {
			count++;
		}
	}

	return count;
}
