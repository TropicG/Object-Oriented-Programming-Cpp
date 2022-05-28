#ifndef WEBSITE
#define WEBSITE
#include "Facebook.h"
#include <fstream>

class Website {
public:
	void load(Facebook& face);
	void save(const Facebook& face);
};
#endif

