#ifndef EXCEPTION
#define EXCEPTION
#include <iostream>

//exceptions for class PictureData
class CommentNotThere : public std::exception {
public:
	const char* what() const throw() {
		return "This comment is not found";
	}
};

//exceptions for class Date
class InvalidDate : public std::exception {
public:
	const char* what() const throw() {
		return "This date is invalid";
	}
};

//exceptions for class UserData
class PicAdded : public std::exception {
public:
	const char* what() const throw() {
		return "This picture is already added";
	}
};
class PicNotAdded : public std::exception {
public:
	const char* what() const throw() {
		return "This picture is not added";
	}
};

//exceptions for class Facebook
class UserAdded : public std::exception {
public:
	const char* what() const throw() {
		return "This user is already added";
	}
};
class UserNotAdded : public std::exception {
public:
	const char* what() const throw() {
		return "This user is not added";
	}
};


#endif