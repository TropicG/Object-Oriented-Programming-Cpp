#ifndef DETAILS
#define DETAILS
#include <iostream>
#include <cstring>

const int manufacturerSize = 32, modelSize = 64;

class Details {
private:
	char* manufac = nullptr;
	char* model = nullptr;
	unsigned year = 0;

private:
	void clear();

public:
	Details();
	Details(const char* manufac, const char* model, const unsigned& year);
	Details& operator=(const Details& other);
	~Details();

	bool operator==(const Details& other) const;

	const char* getManufac() const;
	const char* getModel() const;
	unsigned getYear() const;

	void setManu(const char* manu);
	void setModel(const char* model);
	void setYear(const unsigned& year);

	void print() const;
	void read();
};

#endif
