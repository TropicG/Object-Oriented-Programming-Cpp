#ifndef PENCIL_H
#define PENCIL_H
#include <iostream>
#include <cstring>
#include <fstream>

const int MAX_MODEL = 101;

class Pencil {
private:
	char* model = nullptr;
	int year = 0;
	int tough = 0;

private:
	void clear();

public:
	Pencil();
	Pencil(const char* model, const int& year, const int& tough);
	Pencil(const Pencil& other);
	Pencil& operator=(const Pencil& other);
	~Pencil();

	const char* getModel() const;
	int getYear() const;
	int getTough() const;

	void setModel(const char* model);
	void setYear(const int& year);
	void setTough(const int& tought);

	void read();
	void print() const;

	friend std::ostream& operator<<(std::ostream& os, const Pencil& pencil);
	friend std::istream& operator>>(std::istream& is, Pencil& pencil);
};
#endif 
