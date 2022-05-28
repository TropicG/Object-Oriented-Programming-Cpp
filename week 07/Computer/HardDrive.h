#ifndef HARDDRIVE
#define HARDDRIVE
#include "Component.h"

class HardDrive : public Component {
public:
	HardDrive();
	HardDrive(const char* desc, const int& id);
	HardDrive(const HardDrive& other);

	void read();
	void print() const;
};
#endif