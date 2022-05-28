#include "Dealership.h"
using namespace std;

void printMenu() {
	cout << "1 - add car" << endl;
	cout << "2 - remove car" << endl;
	cout << "3 - change car" << endl;
	cout << "4 - show all cars" << endl;
	cout << endl;
}

bool invalid(const char* command) {

	if (strcmp(command, "horsepower") != 0 && strcmp(command, "mass")!=0
		&& strcmp(command, "type")!=0 && strcmp(command, "doors")!=0 && strcmp(command,"spoiler")!=0
		&& strcmp(command, "color")!=0) {
		return false;
	}

	return true;
}

int main() {

	Dealership d;
	int option = 0;

	printMenu();

	while (true) {

		cin >> option;

		if (option == 1) {

			Car temp;
			temp.read();
			d.addCar(temp);
		}
		else if (option == 2) {

			Car temp;
			temp.read();
			d.removeCar(temp);
		}
		else if (option == 3) {

			char helper[16];
			Car temp;

			temp.read();
			cout << "What do you want to change: ";
			cin >> helper;
			while (!invalid(helper)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid type, try again: ";
				cin >> helper;
			}

			d.changeCar(temp, helper);
		}
		else if (option == 4) {
			d.print();
		}
		else {
			break;
		}

	}
	
	return 0;
}