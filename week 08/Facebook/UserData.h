#ifndef USERDATA
#define USERDATA
#include "PictureData.h"
#include "Date.h"

const int userNameMax = 65;

class UserData {
private:
	std::string name;
	unsigned age = 0;
	Date date;
	std::vector<PictureData*> pics;
	unsigned picSize = 0;

private:
	bool inside(const PictureData& pic) const;

public:
	UserData();
	UserData(const char* name, const unsigned& age, const Date& date);
	UserData(const UserData& other);
	~UserData();

	bool operator==(const UserData& other) const;

	void addPic(const PictureData& pic);
	void delPic(const PictureData& pic);

	PictureData* getPic(const PictureData& pic) const;
	PictureData& operator[](const unsigned& index) const;
	PictureData operator[](const unsigned& index);
	const std::string getName() const;
	unsigned getAge() const;
	unsigned getSize() const;
	Date getDate() const;
	
	void setName(const char* name);
	void setAge(const unsigned& age);
	void setDate(const Date& date);
	
	void print() const;
	void read();

	friend std::ostream& operator<<(std::ostream& os, const UserData& user);
	friend std::istream& operator>>(std::istream& is, UserData& user);
};
#endif