#ifndef HELPERFUNCTIONS
#define HELPERFUNCTIONS
#include <iostream>
using namespace std;

void printMenu() {
	cout << "1 - add fauna to the planet" << endl;
	cout << "2 - add family to a fauna" << endl;
	cout << "3 - add animal to a family in fauna" << endl;
	cout << "4 - add zoo to the planet" << endl;
	cout << "5 - add family to a zoo" << endl;
	cout << "6 - add animal to a family in zoo" << endl;
	cout << "7 - get the number of zoos in the planet" << endl;
	cout << "8 - get the number of faunas in the planet" << endl;
	cout << "9 - get the info about everything in the planet" << endl;
	cout << endl;
}

void inputOption(int& option) {
	cout << "Enter your option: ";
	cin >> option;
	while (cin.fail() || option < 1 || option > 9) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid argument, please try again: ";
		cin >> option;
	}
}

void inputFaunaName(char* faunaName) {
	cout << "Enter the name of the fauna: ";
	if (cin.peek() == '\n') cin.ignore();
	cin.getline(faunaName, faunaNameMax, '\n');
	bool failed = cin.fail();
	if (failed) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void inputFamilyName(char* familyName) {
	cout << "Enter the name of the family: ";
	if (cin.peek() == '\n') cin.ignore();
	cin.getline(familyName, famNameMax, '\n');
	bool failed = cin.fail();
	if (failed) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void inputZooName(char* zooName) {
	cout << "Enter the name of the zoo: ";
	if (cin.peek() == '\n') cin.ignore();
	cin.getline(zooName, zooNameMax, '\n');
	bool failed = cin.fail();
	if (failed) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

#endif