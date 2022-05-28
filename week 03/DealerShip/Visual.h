#ifndef VISUAL
#define VISUAL
#include <iostream>
#include <string>

const int colorSize = 51;

class Visual {
private:
	unsigned doors = 0;
	bool spoiler = false;
	char* color = nullptr;

private:
	void clear();

public:
	Visual();
	Visual(const unsigned& doors, const char* spoiler, const char* color);
	Visual& operator=(const Visual& other);
	~Visual();

	bool operator==(const Visual& other) const;

	unsigned getDoors() const;
	const char* getSpoiler() const;
	const char* getColor() const;

	void setDoors(const unsigned& doors);
	void setSpoiler(const char* spoiler);
	void setColor(const char* color);

	void print() const;
	void read();
};
#endif