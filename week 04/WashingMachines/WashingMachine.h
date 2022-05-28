#ifndef WASCHINGMACHINE
#define WASCHINGMACHINE
#include <iostream>
#include <cstring>

const int manuSize = 32, modelSize = 32;

class WashingMachine {
private:
	char* manu = nullptr;
	char* model = nullptr;
	int mass = 0;
	double wat = 0;
	int water = 0;

public:

	WashingMachine();
	WashingMachine(const char* manu, const char* model, const int& mass, const int& wat, const int& water);
	WashingMachine& operator=(const WashingMachine& other);
	~WashingMachine();

	bool operator<(const WashingMachine& other) const;

	const char* getManu() const;
	const char* getModel() const;
	int getMass() const;
	int getWat() const;
	int getWater() const;
	
	void setManu(const char* manu);
	void setModel(const char* model);
	void setMass(const int& mass);
	void setWat(const int& wat);
	void setWater(const int& water);

	friend std::ostream& operator<<(std::ostream& os, const WashingMachine& wash);
	friend std::istream& operator>>(std::istream& is, WashingMachine& wash);
};

#endif