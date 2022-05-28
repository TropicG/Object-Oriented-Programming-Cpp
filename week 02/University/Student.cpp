#include "Student.h"

bool Student::valid(const char* str)
{
	//checks if there are other symbols than [0-9]
	int size = strlen(str);
	for (int i = 0; i < size; ++i) {
		if (str[i] < '0' || str[i]>'9') return false;
	}
	return true;
}

void Student::input() {

	//gets the name of the student
	char temp[nameSize + 1];
	std::cout << "Enter the name of the student: ";
	std::cin.ignore();
	std::cin.getline(temp, nameSize);
	name = new (std::nothrow) char[strlen(temp) + 1];
	strcpy_s(name, strlen(temp)+1, temp);

	//gets the egn of the student
	std::cout << "Enter the egn of the student: ";
	std::cin >> temp;
	while (strlen(temp) != egnSize || !valid(temp)) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Invalid argument, try again: ";
		std::cin >> temp;
	}
	egn = new (std::nothrow) char[strlen(temp) + 1];
	strcpy_s(egn, strlen(temp) + 1, temp);

	//gets the faculty num of the student
	std::cout << "Enter the faculty number of the student: ";
	std::cin >> temp;
	while (strlen(temp) != facultySize || !valid(temp)) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		std::cout << "Invalid argument, try again: ";
		std::cin >> temp;
	}
	faculty = new (std::nothrow) char[strlen(temp) + 1];
	strcpy_s(faculty, strlen(temp) + 1, temp);

	//inputs the grades
	for (int i = 0; i < gradesCount; ++i) {
		grades[i].input();
	}
}

void Student::output() {
	std::cout << "The name of the Student is: " << name << std::endl;
	std::cout << "The egn of the Student is: " << egn << std::endl;
	std::cout << "The faculty num of the Student is: " << faculty << std::endl;
	std::cout << "The score of the student is: " << result() << std::endl;
}

void Student::clear()
{
	delete[] name;
	delete[] egn;
	delete[] faculty;
	for (int i = 0; i < gradesCount; ++i) {
		grades[i].clear();
	}
}

double Student::result()
{
	double avarage = 0;
	for (int i = 0; i < gradesCount; ++i) {
		avarage += grades[i].getGrade();
	}

	return avarage / gradesCount;
}
