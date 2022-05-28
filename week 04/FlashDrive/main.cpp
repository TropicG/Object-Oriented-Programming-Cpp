#include "FlashDrive.h"
using namespace std;

void printMenu() {
	cout << "1 - add virus to the flashdrive" << endl;
	cout << "2 - add viruses to the flashdrive" << endl;
	cout << "3 - show all viruses" << endl;
	cout << endl;
}

int main() {
	
	FlashDrive flash;
	int option = 0;

	printMenu();

	while (true) {

		cin >> option;

		if (option == 1) {

			cout << "Enter your virus" << endl;
			Virus v;
			cin >> v;
			flash += v;
			cout << "Succsesfully added" << endl;
			cout << endl;
		}
		else if (option == 2) {

			int count = 0;
			cout << "Enter how many viruses you will be adding: ";
			cin >> count;
			while (cin.fail() || count < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max() , '\n');
				cout << "Invalid argument, try again: ";
				cin >> count;
			}

			FlashDrive temp;
			cout << "Enter your viruses" << endl;
			for (int i = 0; i < count; ++i) {
				Virus v;
				cin >> v;
				temp += v;
			}

			flash += temp;
			cout << "Viruses successfully added!" << endl;
			cout << endl;
		}
		else if (option == 3) {

			cout << flash;
		}
		else {
			break;
		}
	}

	return 0;
}