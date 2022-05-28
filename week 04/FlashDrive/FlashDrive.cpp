#include "FlashDrive.h"

FlashDrive::FlashDrive()
{
}

FlashDrive& FlashDrive::operator=(const FlashDrive& other)
{
	if (this != &other) {
		*this += other;
	}

	return *this;
}

FlashDrive::~FlashDrive()
{
	for (int i = 0; i < this->viruses.size(); ++i) {
		delete this->viruses[i];
	}
}

FlashDrive& FlashDrive::operator+=(const Virus& flash)
{
	this->viruses.push_back(new Virus(flash));

	return *this;
}

FlashDrive& FlashDrive::operator+=(const FlashDrive& other)
{
	for (int i = 0; i < other.viruses.size(); ++i) {
		this->viruses.push_back(new Virus(other[i]));
	}

	return *this;
}

const Virus FlashDrive::operator[](const int& index) const
{
	return *this->viruses[index];
}

std::ostream& operator<<(std::ostream& os, const FlashDrive& other)
{
	for (int i = 0; i < other.viruses.size(); ++i) {
		os << other[i];
	}

	return os;
}
