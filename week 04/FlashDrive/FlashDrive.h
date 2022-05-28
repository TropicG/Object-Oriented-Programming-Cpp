#ifndef FLASHDRIVE
#define FLASHDRIVE
#include "Virus.h"
#include <vector>

class FlashDrive {
private:
	std::vector<Virus*> viruses;

public:
	FlashDrive();
	FlashDrive& operator=(const FlashDrive& other);
	~FlashDrive();

	FlashDrive& operator+=(const Virus& flash);
	FlashDrive& operator+=(const FlashDrive& other);

	const Virus operator[](const int& index) const;

	friend std::ostream& operator<<(std::ostream& os, const FlashDrive& other);
};
#endif