#include "University.h"

void printMenu()
{
	std::cout << "1 - Add Student" << std::endl;
	std::cout << "2 - sort Students" << std::endl;
	std::cout << "3 - print Students" << std::endl;
	std::cout << std::endl;
}

int main() {

	int option = 0;
	University uni;

	printMenu();

	while (true) {

		std::cin >> option;

		if (option == 1) {
			uni.addStudent();
			std::cout << std::endl;
		}
		else if (option == 2) {
			uni.sort();
			std::cout << std::endl;
		}
		else if (option == 3) {
			uni.print();
			std::cout << std::endl;
		}
		else {
			break;
		}
	}
	return 0;
}
