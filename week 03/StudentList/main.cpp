#include "StudentList.h"
using namespace std;

void printMenu() {
	cout << "1 - add Student" << endl;
	cout << "2 - remove student by facultyNum" << endl;
	cout << "3 - remove student by information" << endl;
	cout << "4 - check if he Student is there by facultyNum" << endl;
	cout << "5 - check if the student is there by info" << endl;
	cout << "6 - show all students" << endl;
	cout << endl;
}

int main() {

	int capacity = 0;

	cout << "Enter the capacity of the list: ";
	cin >> capacity;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid argument, try again: ";
		cin >> capacity;
	}

	printMenu();

	StudentList list(capacity);
	int option = 0;

	while (true) {

		cin >> option;

		if (option == 1) {
			Student student;
			student.read();
			list.add(student);
		}
		else if (option == 2) {
			int facNum = 0;
			cout << "Enter the facNum: ";
			cin >> facNum;
			list.remove(facNum);
		}
		else if (option == 3) {
			Student student;
			student.read();
			list.remove(student);
		}
		else if (option == 4) {
			int facNum = 0;
			cout << "Enter the facNum : ";
			cin >> facNum;
			if (list.contains(facNum)) {
				cout << "The student is there!" << endl;
			}
			else {
				cout << "The student is not there!" << endl;
			}
		}
		else if (option == 5) {
			Student student;
			student.read();
			if (list.contains(student)) {
				cout << "The student is there!" << endl;
			}
			else {
				cout << "The student is not there!" << endl;
			}
		}
		else if (option == 6) {
			list.print();
		}
		else {
			break;
		}
	}

	return 0;
}