#ifndef NATURAL_NUMBERS_H
#define NATURAL_NUMBERS_H
#include <iostream>
#include <cstring>

const int MAX_NAME = 10000;

class NaturalNumbers {
private:
	int* numbers = nullptr;
	char* name = nullptr;
	int size = 0;

private:
	void clear();
	void initialise(const int& n);

public:
	NaturalNumbers();
	NaturalNumbers(int* numbers, const int& n, const char* name);
	NaturalNumbers(const NaturalNumbers& other);
	NaturalNumbers& operator=(const NaturalNumbers& other);
	~NaturalNumbers();

	NaturalNumbers operator*(const NaturalNumbers& other);
	NaturalNumbers operator*=(const NaturalNumbers& other);
	bool operator[](const int& n) const;

	const int* getNumbers() const;
	const char* getName() const;
	int getSize() const;

	void setNumbers(int* numbers, const int& size);
	void setName(const char* name);
	void setSize(const int& size);

	friend std::ostream& operator<<(std::ostream& os, const NaturalNumbers& natNums);
	friend std::istream& operator>>(std::istream& is, NaturalNumbers& natNums);
};
#endif

