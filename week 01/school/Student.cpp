#include "Student.h"

void Student::correct(char* name)
{
	int size = strlen(name);
	if (name[0] >= 'a' && name[0] <= 'z') {
		name[0] += ('A' - 'a');
	}

	for (int i = 1; i < size-1; ++i) {

		if (name[i] == ' ' && name[i+1] >= 'a' && name[i+1] <= 'z') {
			name[i + 1] += ('A' - 'a');
		}
	}
}

bool Student::valid(const char* str)
{
	int size = strlen(str);
	for (int i = 0; i < size; ++i) {
		if (!(str[i] >= '0' && str[i]<='9'))
			return false;
	}
	return true;
}

void Student::read()
{
	std::cout << "Enter the student's name: ";
	std::cin.ignore();
	std::cin.getline(name, MAX_NAME + 1, '\n');
	correct(name);

	std::cout << "Enter the student's egn: ";
	std::cin.getline(egn, EGN_SIZE + 1, '\n');
	while (strlen(egn) != EGN_SIZE || !valid(egn)) {
		std::cin.clear();
		std::cin.ignore(EGN_SIZE, '\n');
		std::cout << "Invalid argument, try again: ";
		std::cin.getline(egn, EGN_SIZE);
	}

	std::cout << "Enter the student's faculty num: ";
	std::cin.getline(faculty, FACULTY_SIZE + 1, '\n');
	while (strlen(faculty) != 5 || !valid(faculty)) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Invalid argument, try again: ";
		std::cin.getline(faculty, FACULTY_SIZE);
	}

	std::cout << "Enter the studen's grades: " << std::endl;
	for (int i = 0; i < GRADES; ++i) {
		grades[i].read();
	}

}

void Student::print()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Avarage score: " << avarage() << std::endl;
}

int Student::getMonth()
{
	return ((egn[2]-'0')*10 + (egn[3]-'0'));
}

float Student::avarage()
{
	float avar = 0;
	for (int i = 0; i < GRADES; ++i) {
		avar += grades[i].grade;
	}
	return avar / GRADES;
}

void Student::clear()
{
	for (int i = 0; i < GRADES; ++i) {
		grades[i].clear();
	}
}
