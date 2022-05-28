#ifndef FAMILY
#define FAMILY
#include "Animal.h"
#include "exception.h"
#include <vector>
#include <stdexcept>

const int famCap = 6, famNameMax = 65;

class Family {
private:
	char* name = nullptr;
	std::vector<Animal*> members;
	unsigned size = 0;
	unsigned cap = 0;

private:
	bool inside(const Animal& animal) const;
	void clearFamName();
	void clearMembers();

public:
	Family();
	Family(const char* name, const unsigned& cap);
	Family(const Family& other);
	Family& operator=(const Family& other);
	~Family();
	
	void addMember(const Animal& animal);
	void removeMember(const Animal& animal);

	bool operator==(const Family& other);

	Animal& operator[](const int& index) const;
	Animal operator[](const int& index);
	unsigned getSize() const;
	unsigned getCap() const;
	const char* getName() const;

	void setName(const char* name);
	void setSize(const unsigned& size);
	void setCap(const unsigned& cap);
	

	friend std::ostream& operator<<(std::ostream& os, const Family& fam);
	friend std::istream& operator>>(std::istream& is, Family& fam);
};
#endif