#ifndef EXCEPTION
#define EXCEPTION
#include <iostream>

class VolumeOverflow : public std::exception {
public:
	const char* what() const throw() {
		return "There is no more space in the backpack";
	}

};

class WeightOverflow : public std::exception {
public:
	const char* what() const throw() {
		return "The backpack will be too heavy";
	}
};
#endif