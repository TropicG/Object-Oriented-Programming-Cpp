#include "Subject.h"


void Subject::input() {

	char temp[subjectSize];
	std::cout << "Enter the name of the subject: ";
	std::cin >> temp;
	name = new (std::nothrow) char[strlen(temp) + 1];
	strcpy_s(name, strlen(temp) + 1, temp);

	std::cout << "Enter the grade from that subject: ";
	std::cin >> grade;
	while (std::cin.fail() || grade == 0 || grade > 6) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument for grade, please try again: ";
		std::cin >> grade;
	}
}

void Subject::output()
{
	std::cout << "The name of the subject is: " << name << " and the grade is: " << grade << std::endl;
}

void Subject::clear()
{
	delete[] name;
}

unsigned Subject::getGrade()
{
	return grade;
}
