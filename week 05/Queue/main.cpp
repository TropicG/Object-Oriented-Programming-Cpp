#include "Queue.h"
using namespace std;

void printMenu() {
	cout << "1 - add Ticket" << endl;
	cout << "2 - get Ticket by id" << endl;
	cout << "3 - remove most recent Ticket" << endl;
	cout << "4 - check is Queue empty" << endl;
	cout << "5 - get size of the Queue" << endl;
}

void initialiseCap(unsigned& cap) {
	cout << "Enter the cap of the queue: ";
	cin >> cap;
	while (cin.fail() || cap == 0 || cap > 512) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid argument, try again: ";
		cin >> cap;
	}
}

void initialiseOpt(unsigned& option) {
	cout << "Enter command: ";
	cin >> option;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid argument, try again: ";
		cin >> option;
	}
}

void initialiseID(unsigned& id) {
	cout << "Enter id: ";
	cin >> id;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid argument, try again: ";
		cin >> id;
	}
}

int main() {
	
	unsigned cap = 0;
	initialiseCap(cap);
	
	Queue qu(cap);

	printMenu();

	while (true) {
		try {

			unsigned option = 0;
			initialiseOpt(option);

			if (option == 1) {

				Ticket tic;
				cin >> tic;
				qu.addTicket(tic);
				cout << "Successfully added" << endl;
				cout << endl;
			}
			else if (option == 2) {

				unsigned id = 0;
				initialiseID(id);
				cout << "The ticket is: ";
				cout << qu[id] << endl;
			}
			else if (option == 3) {

				qu.next();
				cout << "Succesfully removed" << endl;
				cout << endl;
			}
			else if (option == 4) {

				if (qu.empty()) cout << "The queue is empty" << endl;
				else cout << "The queue is not empty" << endl;
				cout << endl;
			}
			else if (option == 5) {

				cout << "The size of the queue is: " << qu.getSize() << endl;
				cout << endl;
			}
			else {
				break;
			}
		}
		catch (invalid_argument& ia) {
			cout << ia.what() << endl;
		}
		catch (overflow_error oe) {
			cout << oe.what() << endl;
		}
	}

	return 0;
}