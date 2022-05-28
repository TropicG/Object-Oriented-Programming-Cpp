#ifndef BACKPACK
#define BACKPACK
#include "Item.h"
#include "exception.h"
#include <vector>

const int maxv = 128, maxw = 128;

class Backpack {
private:
	double volMax = 0;
	double weiMax = 0; 
	std::vector<Item*> items;

public:
	Backpack();
	Backpack(const double& volume, const double& weight);
	~Backpack();

	void add(const Item& item);
	Item operator[](const int& index) const;

	int getSize() const;

	double leftVolume() const;
	double leftWeight() const;

	void setWeight(const double& weight);
	void setVolume(const double& volume);
};
#endif

