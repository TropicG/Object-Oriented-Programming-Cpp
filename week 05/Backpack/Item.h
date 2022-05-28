#ifndef ITEM
#define ITEM
#include <iostream>
#include <cstring>

const int nameSize = 65;

class Item {
private:
	char* name = nullptr;
	double weight = 0;
	double volume = 0;

public:
	Item();
	Item(const char* name, const double& weight, const double& volume);
	Item(const Item& other);
	Item& operator=(const Item& other);
	~Item();

	bool operator==(const Item& item) const;
	bool operator>(const Item& item) const;

	const char* getName() const;
	double getWeight() const;
	double getVolume() const;

	void setName(const char* name);
	void setWeight(const double& weight);
	void setVolume(const double& volume);

	friend std::ostream& operator<<(std::ostream& os, const Item& item);
	friend std::istream& operator>>(std::istream& is, Item& item);
};
#endif

