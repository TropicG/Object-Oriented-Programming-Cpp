#ifndef HORO
#define HORO
#include <cstring>
#include <iostream>

class Horo
{
private:
	char* name;
	char* tact;
	char* field;
public:

	Horo();
	Horo(const char* name, const char* tack, const char* field);
	Horo(const Horo& other);
	~Horo();

	char* getName() const;
	char* getTack() const;
	char* getField() const;

	void setName(const char* name);
	void setTack(const char* tack);
	void setField(const char* field);
};
#endif
