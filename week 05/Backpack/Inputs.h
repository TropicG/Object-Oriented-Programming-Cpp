#ifndef INPUT
#define INPUT
#include <iostream>
using namespace std;

void inputVol(double& vol) {

	cout << "Enter the volume for the backpack: ";
	cin >> vol;
	while (cin.fail() || vol <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
		cout << "Invalid argument, try again: ";
		cin >> vol;
	}
}

void inputWei(double& wei) {

	cout << "Enter the weight for the backpack: ";
	cin >> wei;
	while (cin.fail() || wei <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> wei;
	}
}

void inputOption(short& option) {

	cout << "Enter the command: ";
	cin >> option;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> option;
	}
}

void inputIndex(int& index) {
	cout << "Enter index: ";
	cin >> index;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> index;
	}
}

void printMenu() {
	cout << "1 - add item" << endl;
	cout << "2 - get item by index" << endl;
	cout << "3 - get size" << endl;
	cout << "4 - check how many free volume left" << endl;
	cout << "5 - check how many free weight left" << endl;
	cout << endl;
}
#endif
