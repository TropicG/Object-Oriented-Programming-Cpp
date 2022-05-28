#include "Subject.h"

void Subject::read()
{
	char temp[MAX_SUBJECT];
	std::cout << "Enter the name of the subject: ";
	std::cin.ignore();
	std::cin.getline(temp, MAX_SUBJECT);

	subject = new (std::nothrow) char[strlen(temp) + 1];
	if (!subject) {
		std::cout << "Failder!" << std::endl;
		delete[] subject;
		return;
	}
	strcpy_s(subject, strlen(temp) + 1, temp);

	std::cout << "Enter the grade from the subject: ";
	std::cin >> grade;
	while (std::cin.fail() || grade < 2 || grade>6) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Invalid argument for grade, try again: ";
		std::cin >> grade;
	}
}

void Subject::clear()
{
	delete[] subject;
}
