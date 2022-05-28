#ifndef COMPONENT
#define COMPONENT
#include <iostream>
#include <cstring>

class Component {
protected:
	std::string desc;
	int id = 0;

public:
	Component();
	Component(const char* desc, const int& id);
	Component(const Component& other);

	const std::string getDesc() const;
	int getId() const;

	void setDesc(const char* desc);
	void setId(const int& id);

	void print() const;
	void read();
};
#endif