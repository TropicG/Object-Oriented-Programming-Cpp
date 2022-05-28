#include "School.h"
using namespace std;

void printMenu()
{
	cout << "1 - Add Student" << endl;
	cout << "2 - Get all the students from March" << endl;
	cout << "3 - Get the best students" << endl;
}

int main()
{
	School school;
	int option=0;

	printMenu();


	do {

		cin >> option;

		switch (option)
		{
			case 1:
				school.addStudent();
				break;
			case 2:
				school.bornMarch();
				break;
			case 3:
				school.printBestStudent();
				break;
		}

	} while (option);

	return 0;
}
