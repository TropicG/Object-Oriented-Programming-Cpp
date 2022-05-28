#include "Commentar.h"

Comment::Comment()
{
}

Comment::Comment(const char* com)
{
	this->setComment(com);
}

Comment::Comment(const Comment& other)
{
	this->setComment(other.getComment().c_str());
}

bool Comment::operator==(const Comment& other) const
{
	return this->com == other.com;
}

const std::string Comment::getComment() const
{
	return this->com;
}

void Comment::setComment(const char* com)
{
	this->com = com;
}

void Comment::print() const
{
	std::cout << com << std::endl;
}

void Comment::read() 
{
	char com[commentMaxSize];
	std::cout << "Enter the comment: ";
	if (std::cin.peek() == '\n') std::cin.ignore();
	std::cin.getline(com, commentMaxSize, '\n');
	bool failed = std::cin.fail();
	if (failed) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	this->setComment(com);
}

std::ostream& operator<<(std::ostream& os, const Comment& com)
{
	os << com.com << std::endl;
	
	return os;
}

std::istream& operator>>(std::istream& is, Comment& com)
{
	char comm[commentMaxSize];
	if (is.peek() == '\n') is.ignore();
	is.getline(comm, commentMaxSize, '\n');
	com.setComment(comm);

	return is;
}
