#ifndef STRING_H
#define STRING_H
#include <iostream>

//the max accepted input in read function
const int MAX_INPUT = 2048 + 1;

class String {
private:
	char* str = nullptr;
	int size = 0;

private:

	//getting the length of the argument
	int getLength(const char* str);

	//alocating and deleting memory
	void aloc(const int& cap);
	void del();

public:
	String();
	String(const int& size);
	String(const char* str);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	String& operator+=(const char* str);

	//checks are two String objects equal
	bool operator==(const String& other) const;

	//Returns the char at the given index
	char operator[](const int& index) const;

	//getters
	const char* getStr() const;
	int getSize() const;

	//setters
	void setStr(const char* str);

	//printing to the console and reading from the console
	void read();
	void print() const;
};
#endif