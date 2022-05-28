#ifndef PLANET
#define PLANET
#include "Fauna.h"
#include "Zoo.h"

const int planetNameMax = 65;

class Planet {
private:
	char* name = nullptr;
	std::vector<Fauna*> faunas;
	std::vector<Zoo*> zoos;

	unsigned faunaCap = 0;
	unsigned zooCap = 0;

	unsigned faunaSize = 0;
	unsigned zooSize = 0;

private:
	void clearName();
	void clearFaunas();
	void clearZoos();

	bool insideFauna(const char* faunaName) const;
	bool insideZoo(const char* zooName) const;

	Fauna* getFauna(const char* faunaName);
	Zoo* getZoo(const char* zooName); 

public:
	Planet();
	Planet(const char* name, const unsigned& faunaCap, const unsigned& zooCap);
	Planet(const Planet& other);
	Planet& operator=(const Planet& other);
	~Planet();

	void addFauna(const Fauna& fauna);
	void addFamilyInFauna(const char* faunaName, const Family& family);
	void addAnimalInFamilyInFauna(const char* faunaName, const char* familyName, const Animal& animal);

	void removeFauna(const char* faunaName);
	void removeFamilyInFauna(const char* faunaName, const Family& family);
	void removeAnimalInFamilyInFauna(const char* faunaName, const char* familyName, const Animal& animal);

	void addZoo(const Zoo& zoo);
	void addFamilyInZoo(const char* zooName, const Family& family);
	void addAnimalInFamilyInZoo(const char* zooName, const char* familyName, const Animal& animal);

	void removeZoo(const char* zooName);
	void removeFamilyInZoo(const char* zooName, const Family& family);
	void removeAnimalInFamilyInZoo(const char* faunaName, const char* familyName, const Animal& animal);

	Fauna& atFauna(const unsigned& index) const;
	Fauna atFauna(const unsigned& index);

	Zoo& atZoo(const unsigned& index) const;
	Zoo atZoo(const unsigned& index);
	
	const char* getName() const;
	unsigned getFaunaCap() const;
	unsigned getZooCap() const;
	unsigned getFaunaSize() const;
	unsigned getZooSize() const;

	void setName(const char* name);
	void setFaunaCap(const unsigned& faunaCap);
	void setZooCap(const unsigned& zooCap);
	void setFaunaSize(const unsigned& faunaSize);
	void setZooSize(const unsigned& zooSize);

	friend std::ostream& operator<<(std::ostream& os, const Planet& planet);
	friend std::istream& operator>>(std::istream& is, Planet& planet);
};
#endif