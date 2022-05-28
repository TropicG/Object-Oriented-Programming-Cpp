#include "UserData.h"

bool UserData::inside(const PictureData& pic) const
{
	for (int i = 0; i < picSize; ++i) {
		if (*this->pics[i] == pic) {
			return true;
		}
	}

	return false;
}

UserData::UserData()
{
}

UserData::UserData(const char* name, const unsigned& age, const Date& date)
{
	this->setName(name);
	this->setAge(age);
	this->setDate(date);
}

UserData::UserData(const UserData& other)
{
	this->setName(other.getName().c_str());
	this->setAge(other.getAge());
	this->setDate(other.getDate());
	for (int i = 0; i < other.pics.size(); ++i) {
		this->pics.push_back(new PictureData(other[i]));
	}
}

UserData::~UserData()
{
	for (int i = 0; i < this->pics.size(); ++i) {
		delete this->pics[i];
	}
}

bool UserData::operator==(const UserData& other) const
{
	return this->getName() == other.getName();
}

void UserData::addPic(const PictureData& pic)
{
	if (inside(pic)) {
		throw PicAdded();
	}

	this->pics.push_back(new PictureData(pic));
	this->picSize++;
}

void UserData::delPic(const PictureData& pic)
{
	if (!inside(pic)) {
		throw PicNotAdded();
	}

	for (int i = 0; i < this->pics.size(); ++i) {
		if (*this->pics[i] == pic) {
			this->pics.erase(this->pics.begin() + i);
			break;
		}
	}
	this->picSize--;
}

PictureData* UserData::getPic(const PictureData& pic) const
{
	for (int i = 0; i < this->pics.size(); ++i) {
		if (*this->pics[i] == pic) {
			return this->pics[i];
		}
	}

	return nullptr;
}

PictureData& UserData::operator[](const unsigned& index) const
{
	return *this->pics[index];
}

PictureData UserData::operator[](const unsigned& index)
{
	return *this->pics[index];
}

const std::string UserData::getName() const
{
	return this->name;
}

unsigned UserData::getAge() const
{
	return this->age;
}

unsigned UserData::getSize() const
{
	return this->picSize;
}

Date UserData::getDate() const
{
	return this->date;
}

void UserData::setName(const char* name)
{
	this->name = name;
}

void UserData::setAge(const unsigned& age)
{
	this->age = age;
}

void UserData::setDate(const Date& date)
{
	this->date = date;
}

void UserData::print() const
{
	std::cout << "The name of the user is " << this->getName() << " and its age is " << this->getAge() << " with registration date ";
	this->getDate().print();
	std::cout << std::endl;
	for (int i = 0; i < this->pics.size(); ++i) {
		this->pics[i]->print();
	}
}

void UserData::read()
{
	std::string name;
	std::cout << "Enter the name of the user: ";
	std::cin >> name;
	this->setName(name.c_str());

	unsigned age = 0;
	std::cout << "Enter the age of the user: ";
	std::cin >> age;
	while (std::cin.fail() || age == 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, please try again";
		std::cin >> age;
	}
	this->setAge(age);

	Date temp;
	temp.read();
	this->setDate(temp);
}

std::ostream& operator<<(std::ostream& os, const UserData& user)
{
	os << user.getName() << " " << user.getAge() << " " << user.getDate()  << " " << user.getSize() << std::endl;
	for (int i = 0; i < user.pics.size(); ++i) {
		os << user[i];
	}

	return os;
}

std::istream& operator>>(std::istream& is, UserData& user)
{
	is >> user.name >> user.age >> user.date >> user.picSize;
	for (int i = 0; i < user.picSize; ++i) {
		PictureData temp;
		is >> temp;
		user.pics.push_back(new PictureData(temp));
	}

	return is;
}
