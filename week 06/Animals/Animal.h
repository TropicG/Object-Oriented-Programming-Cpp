#ifndef ANIMAL
#define ANIMAL
#include <iostream>
#include <cstring>

const int aniNameMax = 33;

class Animal {
private:
	char* name = nullptr;

private:
	void clearName();

public:
	Animal();
	Animal(const char* name);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	~Animal();
	
	bool operator==(const Animal& other);

	const char* getName() const;
	
	void setName(const char* name);

	friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
	friend std::istream& operator>>(std::istream& is, Animal& animal);
};
#endif