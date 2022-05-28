#ifndef RAM
#define RAM
#include "Component.h"

class Ram : public Component {
public:
	Ram();
	Ram(const char* desc, const int& id);
	Ram(const Ram& other);

	void read();
	void print() const;
};
#endif

