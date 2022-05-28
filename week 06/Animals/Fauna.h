#ifndef FAUNA
#define FAUNA
#include "Family.h"

const int faunaCapMax = 128, faunaNameMax = 65;

class Fauna {
private:
	char* name = nullptr;
	std::vector<Family*> families;
	unsigned size = 0;
	unsigned cap = 0;

private:
	void clearName();
	void clearFamilies();
	bool inside(const char* name);
	Family* getFamily(const char* name);

public:
	Fauna();
	Fauna(const char* name, const unsigned cap);
	Fauna(const Fauna& other);
	Fauna& operator=(const Fauna& other);
	~Fauna();

	void addFamily(const Family& fam);
	void removeFamily(const Family& fam);

	void addToFamily(const char* famName, const Animal& ani);
	void removeFromFamily(const char* famName, const Animal& ani);

	bool operator==(const Fauna& other) const;

	Family& operator[](const unsigned& index) const;
	Family operator[](const unsigned& index);
	const char* getName() const;
	unsigned getCap() const;
	unsigned getSize() const;

	void setName(const char* name);
	void setCap(const unsigned& cap);
	void setSize(const unsigned& size);

	friend std::ostream& operator<<(std::ostream& os, const Fauna& fauna);
	friend std::istream& operator>>(std::istream& is, Fauna& fauna);
};
#endif
