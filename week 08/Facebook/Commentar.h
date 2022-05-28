#ifndef COMMENT
#define COMMENT
#include <iostream>
#include <string>

const int commentMaxSize = 257;

class Comment {
private:
	std::string com;

public:
	Comment();
	Comment(const char* com);
	Comment(const Comment& other);

	bool operator==(const Comment& other) const; 

	const std::string getComment() const;

	void setComment(const char* com);

	void print() const;
	void read();

	friend std::ostream& operator<<(std::ostream& os, const Comment& com);
	friend std::istream& operator>>(std::istream& is, Comment& com);
};
#endif
