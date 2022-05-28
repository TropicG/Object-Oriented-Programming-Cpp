#ifndef FACEBOOK
#define FACEBOOK
#include "UserData.h"

class Facebook {
private:
	std::vector<UserData*> users;
	unsigned usersSize = 0;

private:
	bool inside(const std::string& username) const;
	UserData* getUser(const std::string& username) const;

public:
	Facebook();
	~Facebook();

	void addUser(const UserData& user);
	void addPicToUser(std::string username, const PictureData& pic);
	void addComToPicToUser(std::string username, const PictureData& pic, const Comment& com);

	void delUser(const UserData& user);
	void delPicFromUser(std::string username, const PictureData& pic);
	void delComFromPicFromUser(std::string username, const PictureData& pic, const Comment& com);

	UserData& operator[](const unsigned& index) const;
	UserData& operator[](const unsigned& index);
	unsigned getSize() const;

	void print() const;

	friend std::ostream& operator<<(std::ostream& os, const Facebook& face);
	friend std::istream& operator>>(std::istream& is, Facebook& face);
};
#endif