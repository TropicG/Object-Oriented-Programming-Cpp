#include "String.h"

void String::aloc(const int& cap)
{
	this->str = new char[cap + 1];
}

void String::del()
{
	delete[] this->str;
}

int String::getLength(const char* str)
{
	int cnt = 0;

	//adding to cnt until we meet nullptr
	while (*str != '\0') {
		cnt++;
		str++;
	}

	return cnt;
}


String::String() : str(nullptr), size(0)
{
}

String::String(const int& size) : size(0)
{
	this->del();
	this->aloc(size);
}

String::String(const char* str)
{
	this->size = getLength(str);
	this->setStr(str);
}

String::String(const String& other)
{
	this->size = other.getSize();
	this->setStr(other.getStr());
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		this->size = other.getSize();
		this->setStr(other.getStr());
	}

	return *this;
}

String::~String()
{
	this->del();
}

String& String::operator+=(const char* str)
{
	int strSize = this->getLength(str);

	for (int i = 0; i < strSize; ++i) this->str[this->size++] = str[i];

	return *this;
}

bool String::operator==(const String& other) const
{
	//if the two sizes are different we return false
	if (this->size != other.size) return false;

	//if we meet diff symbol at given loc we return false
	for (int i = 0; i < this->size; ++i) {
		if (this->str[i] != other.str[i]) return false;
	}

	return true;
}

char String::operator[](const int& index) const
{
	if (index >= this->size) { std::cout << "Invalid index"; return '\0'; }

	return this->str[index];
}

const char* String::getStr() const
{
	return this->str;
}

int String::getSize() const
{
	return this->size;
}

void String::setStr(const char* str)
{
	this->aloc(this->size + 1);
	if (!str) { std::cout << "Failed memory allocation"; return; }

	for (int i = 0; i < this->size; ++i) {
		this->str[i] = str[i];
	}

	this->str[this->size] = '\0';
}

void String::read()
{

	//This is the only code i used which is not mine
	//The source is a blog of a programmer who talked how to handle char arrays
	char str[MAX_INPUT];
	if (std::cin.peek() == '\n') std::cin.ignore();
	std::cin.getline(str, MAX_INPUT, '\n');

	bool failed = std::cin.fail();
	if (failed) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//here ends the code that is not mine

	this->size = this->getLength(str);
	this->setStr(str);

}

void String::print() const
{
	std::cout << "\"" << this->str << "\"";
}

