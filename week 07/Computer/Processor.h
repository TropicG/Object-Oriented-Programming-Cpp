#ifndef PROCESSOR
#define PROCESSOR
#include "Component.h"

class Processor : public Component {
public:
	Processor();
	Processor(const char* desc, const int& id);
	Processor(const Processor& other);

	void read();
	void print() const;
};
#endif

