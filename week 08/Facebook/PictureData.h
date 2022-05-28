#ifndef PICTUREDATA
#define PICTUREDATA
#include "Commentar.h"
#include "exception.h"
#include <vector>

const int descMaxSize = 257;

class PictureData {
private:
	std::string desc;
	unsigned likes = 0;
	std::vector<Comment*> coms;
	unsigned comsCount = 0;

private:
	bool inside(const Comment& com) const;

public:
	PictureData();
	PictureData(const char* desc, const unsigned& likes);
	PictureData(const PictureData& other);
	~PictureData();

	void addComment(const Comment& com);
	void delComment(const Comment& com);

	bool operator==(const PictureData& other) const;

	Comment& operator[](const int& index) const;
	Comment operator[](const int& index);
	const std::string getDesc() const;
	unsigned getLikes() const;
	unsigned getComsCount() const;

	void setDesc(const char* desc);
	void setLikes(const unsigned& likes);
	void setComsCount(const unsigned& comscount);

	void print() const;
	void read();

	friend std::ostream& operator<<(std::ostream& os, const PictureData& pic);
	friend std::istream& operator>>(std::istream& is, PictureData& pic);
};
#endif

