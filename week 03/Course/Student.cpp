#include "Student.h"

void Student::setName(const char* name)
{
	if (strlen(name) > nameSize) {
		strcpy_s(this->name, strlen("Name not Added") + 1, "Name not Added");
	}
	else {
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

void Student::setFaculty(const int& faculty)
{
	if (faculty >= 10000 && faculty <= 99999) {
		this->facultyNumber = faculty;
	}
	else {
		this->facultyNumber = 0;
	}
}

void Student::setMajor(const char* major)
{
	if (!inside(major)) {
		strcpy_s(this->major, strlen("Major not Chosen") + 1, "Major not Chosen");
	}
	else {
		strcpy_s(this->major, strlen(major) + 1, major);
	}
}

void Student::setGroup(const int& group)
{
	if (group >= 1 && group <= 8) {
		this->group = group;
	}
	else {
		this->group = 0;
	}
}

unsigned Student::getFaculty() const
{
	return this->facultyNumber;
}

const char* Student::getName() const
{
	return this->name;
}

const char* Student::getMajor() const
{
	return this->major;
}

unsigned Student::getGruop() const
{
	return this->group;
}

void Student::print() const
{
	std::cout << "The name of the student is: " << this->getName() << std::endl;
	std::cout << "The major of the student is : " << this->getMajor() << std::endl;
	std::cout << "The faculty number of the student is: " << this->getFaculty() << std::endl;
	std::cout << "The student is in: " << this->getGruop() << " group" << std::endl;
	std::cout << std::endl;
}

void Student::read()
{
	char temp[maxMaj];

	std::cout << "Enter the Student's name: ";
	std::cin >> temp;
	this->setName(temp);

	std::cout << "Enter the Student's major: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	std::cin.getline(temp, maxMaj ,'\n');
	this->setMajor(temp);

	int helper = 0;
	std::cout << "Enter the Student's group: ";
	std::cin >> helper;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument";
		std::cin >> helper;
	}
	this->setGroup(helper);

	std::cout << "Enter the Student's faculty number: ";
	std::cin >> helper;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument";
		std::cin >> helper;
	}
	this->setFaculty(helper);
}

bool Student::inside(const char* str) const
{
	for (int i = 0; i < maj; ++i) 
	{
		if (strcmp(str, bachalors[i]) == 0) {
			return true;
		}
	}
	return false;
}

Student::Student() : facultyNumber(0), name("Name not Added"), major("Major not Choosen"), group(0)
{
}

Student::Student(const unsigned& facultyNumber, const char* name, const char* major, const int& group)
{
	this->setFaculty(facultyNumber);
	this->setName(name);
	this->setMajor(major);
	this->setGroup(group);
}

Student::Student(const Student& other)
{
	this->setFaculty(other.getFaculty());
	this->setName(other.getName());
	this->setMajor(other.getMajor());
	this->setGroup(other.getGruop());
}

bool Student::equal(const Student& other) const
{
	return this->getFaculty() == other.getFaculty();
}

