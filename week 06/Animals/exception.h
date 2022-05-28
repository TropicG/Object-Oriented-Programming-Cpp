#ifndef EXCEPTION
#define EXCEPTION
#include <iostream>

//exceptions for family class
class FamilyOverflow : public std::exception {
public:
	const char* what() const throw() {
		return "There is no more space in the family";
	}
};

class AnimalThere : public std::exception {
public:
	const char* what() const throw() {
		return "This animal is already in the family";
	}
};

class AnimalNotThere : public std::exception {
public:
	const char* what() const throw(){
		return "This animal is not in the family";
	}
};

class EmptyFamily : public std::exception {
public:
	const char* what() const throw() {
		return "The family is empty";
	}
};


//exceptions for fauna class
class FaunaOverflow : public std::exception {
public:
	const char* what() const throw() {
		return "The fauna has no more space";
	}
};

class FaunaEmpty : public std::exception {
public:
	const char* what() const throw() {
		return "The fauna is empty";
	}
};

//exceptions for zoo class
class ZooOverflow : public std::exception {
public:
	const char* what() const throw() {
		return "The zoo has no more space";
	}
};

class ZooEmpty : public std::exception {
public:
	const char* what() const throw() {
		return "The zoo is empty";
	}
};

//exceptions for both Zoo and Fauna classes
class FamilyThere : public std::exception {
public:
	const char* what() const throw() {
		return "The family is in this fauna or in this zoo";
	}
};
class FamilyNotThere : public std::exception {
public:
	const char* what() const throw() {
		return "The family is not in this fauna or in this zoo";
	}
};

//exceptions for Planet 
class FaunaThere : public std::exception {
public:
	const char* what() const throw() {
		return "The fauna is in the planet";
	}
};

class PlanetFaunaOverflow : public std::exception {
public:
	const char* what() const throw() {
		return "There is no more space for faunas in the planet";
	}
};

class FaunaNotThere : public std::exception {
public:
	const char* what() const throw() {
		return "The fauna is not in the planet";
	}
};

class PlanetFaunaEmpty : public std::exception {
public:
	const char* what() const throw() {
		return "There are no faunas in the planet";
	}
};


#endif