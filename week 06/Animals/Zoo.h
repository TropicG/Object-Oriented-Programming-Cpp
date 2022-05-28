#ifndef ZOO
#define ZOO
#include "Family.h"

const int zooMaxCap = 64, zooNameMax = 65;

class Zoo {
private:
	char* name;
	std::vector<Family*> families;
	unsigned cap = 0;
	unsigned size = 0;

private:
	void clearName();
	void clearFamilies();
	bool inside(const char* name) const;
	Family* getFamily(const char* name);

public:
	Zoo();
	Zoo(const char* name, const unsigned& cap);
	Zoo(const Zoo& other);
	Zoo& operator=(const Zoo& other);
	~Zoo();

	void addFamily(const Family& family);
	void removeFamily(const Family& family);

	void addToFamily(const char* famName, const Animal& animal);
	void removeFromFamily(const char* famName, const Animal& animal);

	bool operator==(const Zoo& other) const;

	Family& operator[](const unsigned& index) const;
	Family operator[](const unsigned& index);
	const char* getName() const;
	unsigned getCap() const;
	unsigned getSize() const;

	void setName(const char* name);
	void setCap(const unsigned& cap);
	void setSize(const unsigned& size);

	friend std::ostream& operator<<(std::ostream& os, const Zoo& zoo);
	friend std::istream& operator>>(std::istream& is, Zoo& zoo);
};
#endif