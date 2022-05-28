#ifndef ENGINE
#define ENGINE
#include <iostream>
#include <cstring>

class Engine {
private:
	unsigned horsePower = 0;
	unsigned mass = 0;
	char* type = nullptr;

private:
	bool valid(const char* type) const;
	void clear();

public:
	Engine();
	Engine(const unsigned& horsePower, const unsigned& mass, const char* type);
	Engine& operator=(const Engine& other);
	~Engine();

	bool operator==(const Engine& other) const;

	unsigned getHorse() const;
	unsigned getMass() const;
	const char* getType() const;

	void setHorse(const int& horsePower);
	void setMass(const int& mass);
	void setType(const char* type);

	void print() const;
	void read();
};
#endif
