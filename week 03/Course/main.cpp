#include "Course.h"
using namespace std;

void printMenu() {
	cout << "1 - add Student" << endl;
	cout << "2 - add multiple Students" << endl;
	cout << "3 - show all students" << endl;
	cout << endl;
}

int main() {

	int capacity = 0;

	cout << "Enter the capacity of the list: ";
	cin >> capacity;
	while (cin.fail() || capacity>maxCapacity || capacity < 0) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid argument, try again: ";
		cin >> capacity;
	}

	printMenu();

	Course course(capacity, "FMI");
	int option = 0;

	while (true) {

		cin >> option;

		if (option == 1) {

			Student newStudent;
			newStudent.read();
			course.enrolStudent(newStudent);
			cout << "Student added!" << endl;
			cout << endl;
		}
		else if (option == 2) {

			vector<Student> studs;
			int size = 0;
			cout << "How many students are you goind to add: ";
			cin >> size;
			while (cin.fail() || size < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid argument, try again: ";
				cin >> size;
			}

			cout << "Enter your students!" << endl;
			for (int i = 0; i < size; ++i) {
				Student newStud;
				newStud.read();
				cout << endl;
				studs.push_back(newStud);
			}

			course.enrolStudents(studs);
			cout << "Students added!" << endl;
			cout << endl;
		}
		else if (option == 3) {
			course.printInformation();
		}
		else {
			break;
		}
	}

	return 0;
}