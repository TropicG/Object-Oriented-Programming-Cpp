#include "Backpack.h"

Backpack::Backpack() : volMax(maxv), weiMax(maxw)
{
}

Backpack::Backpack(const double& volume, const double& weight)
{
	this->setVolume(volume);
	this->setWeight(weight);
}

Backpack::~Backpack()
{
	for (int i = 0; i < this->getSize(); ++i) {
		delete this->items[i];
	}
}

void Backpack::add(const Item& item)
{
	if (this->leftVolume() < item.getVolume()) {
		throw VolumeOverflow();
	}
	if (this->leftWeight() < item.getWeight()) {
		throw WeightOverflow();
	}

	this->items.push_back(new (std::nothrow) Item(item));
}

Item Backpack::operator[](const int& index) const
{
	if (index >= this->getSize()) {
		throw std::out_of_range("Invalid index");
	}

	return *this->items[index];
}

int Backpack::getSize() const
{
	return this->items.size();
}

double Backpack::leftVolume() const
{
	double volume = volMax;
	for (int i = 0; i < this->getSize(); ++i) {
		volume -= this->items[i]->getVolume();
	}

	return volume;
}

double Backpack::leftWeight() const
{
	double weight = weiMax;
	for (int i = 0; i < this->getSize(); ++i) {
		weight -= this->items[i]->getWeight();
	}

	return weight;
}

void Backpack::setWeight(const double& weight)
{
	this->weiMax = weight;
}

void Backpack::setVolume(const double& volume)
{
	this->volMax = volume;
}
