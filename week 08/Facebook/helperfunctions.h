#ifndef HELPERFUNCTIONS
#define HELPERFUNCTIONS
#include <iostream>
using namespace std;

void printMenu() {
	cout << "1 - add user to Facebook" << endl;
	cout << "2 - add pic to a user in Facebook" << endl;
	cout << "3 - add comment to pic to a user in Facebook" << endl;
	cout << "4 - del user from Facebook" << endl;
	cout << "5 - del pic from a user in Facebook" << endl;
	cout << "6 - del comment from a pic from a user in Facebook" << endl;
	cout << "7 - show all users" << endl;
	cout << "8 - load information and close program" << endl;
	cout << endl;
}

void inputOption(unsigned& option) {
	cout << "Enter option: " << endl;
	cin >> option;
	while (cin.fail() || option == 0 || option > 8) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid argument, please try again: ";
		cin >> option;
	}
}

#endif