#ifndef HELPERFUNCTIONS
#define HELPERFUNCTIONS
#include <iostream>
using namespace std;

void printMenu() {
	std::cout << "1 - change ram" << endl;
	std::cout << "2 - change processor" << endl;
	std::cout << "3 - change hard drive" << endl;
	std::cout << "4 - change video card" << endl;
	std::cout << "5 - see computer" << endl;
	std::cout << endl;
}

void initialiseOption(int& option) {
	std::cout << "Enter option: ";
	cin >> option;
}
#endif