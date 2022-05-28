#include "Facebook.h"

bool Facebook::inside(const std::string& username) const
{
	for (int i = 0; i < this->users.size(); ++i) {
		if (this->users[i]->getName() == username) {
			return true;
		}
	}
	
	return false;
}

UserData* Facebook::getUser(const std::string& username) const
{
	for (int i = 0; i < this->users.size(); ++i) {
		if (this->users[i]->getName() == username) {
			return this->users[i];
		}
	}

	return nullptr;
}

Facebook::Facebook()
{
}

Facebook::~Facebook()
{
	for (int i = 0; i < this->users.size(); ++i) {
		delete this->users[i];
	}
}

void Facebook::addUser(const UserData& user)
{
	if (inside(user.getName())) {
		throw UserAdded();
	}

	this->users.push_back(new UserData(user));
	this->usersSize++;
}

void Facebook::addPicToUser(std::string username, const PictureData& pic)
{
	if (!inside(username)) {
		throw UserNotAdded();
	}

	UserData* temp = this->getUser(username);
	temp->addPic(pic);
}

void Facebook::addComToPicToUser(std::string username, const PictureData& pic, const Comment& com)
{
	if (!inside(username)) {
		throw UserNotAdded();
	}

	UserData* temp = this->getUser(username);
	temp->getPic(pic)->addComment(com);
}

void Facebook::delUser(const UserData& user)
{
	if (!inside(user.getName())) {
		throw UserNotAdded();
	}

	for (int i = 0; i < this->users.size(); ++i) {
		if (*this->users[i] == user) {
			this->users.erase(this->users.begin() + i);
			break;
		}
	}
	this->usersSize--;
}

void Facebook::delPicFromUser(std::string username, const PictureData& pic)
{
	if (!inside(username)) {
		throw UserNotAdded();
	}

	UserData* temp = this->getUser(username);
	temp->delPic(pic);
}

void Facebook::delComFromPicFromUser(std::string username, const PictureData& pic, const Comment& com)
{
	if (!inside(username)) {
		throw UserNotAdded();
	}

	UserData* temp = this->getUser(username);
	temp->getPic(pic)->delComment(com);
}

UserData& Facebook::operator[](const unsigned& index) const
{
	return *this->users[index];
}

UserData& Facebook::operator[](const unsigned& index)
{
	return *this->users[index];
}

unsigned Facebook::getSize() const
{
	return 0;
}

void Facebook::print() const
{
	for (int i = 0; i < this->users.size(); ++i) {
		this->users[i]->print();
	}
}

std::ostream& operator<<(std::ostream& os, const Facebook& face)
{
	os << face.usersSize << std::endl;
	for (int i = 0; i < face.users.size(); ++i) {
		os << *face.users[i] << std::endl;
	}

	return os;
}

std::istream& operator>>(std::istream& is, Facebook& face)
{
	is >> face.usersSize;
	for (int i = 0; i < face.usersSize; ++i) {
		UserData temp;
		is >> temp;
		face.users.push_back(new UserData(temp));
	}

	return is;
}
