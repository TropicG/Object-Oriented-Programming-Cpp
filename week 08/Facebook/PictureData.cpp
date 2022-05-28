#include "PictureData.h"

bool PictureData::inside(const Comment& com) const
{
	for (int i = 0; i < this->coms.size(); ++i) {
		if (*this->coms[i] == com) {
			return true;
		}
	}

	return false;
}

PictureData::PictureData()
{
}

PictureData::PictureData(const char* desc, const unsigned& likes)
{
	this->setDesc(desc);
	this->setLikes(likes);
}

PictureData::PictureData(const PictureData& other)
{
	this->setDesc(other.getDesc().c_str());
	this->setLikes(other.getLikes());
	this->setComsCount(other.getComsCount());
	for (int i = 0; i < other.coms.size(); ++i) {
		this->coms.push_back(new Comment(*other.coms[i]));
	}
}

PictureData::~PictureData()
{
	for (int i = 0; i < this->coms.size(); ++i) {
		delete this->coms[i];
	}
}

void PictureData::addComment(const Comment& com)
{
	this->coms.push_back(new Comment(com));
	this->comsCount++;
}

void PictureData::delComment(const Comment& com)
{
	if (!inside(com)) {
		throw CommentNotThere();
	}

	for (int i = 0; i < this->coms.size(); ++i) {
		if (*this->coms[i] == com) {
			this->coms.erase(this->coms.begin() + i);
			break;
		}
	}
	this->comsCount--;
}

bool PictureData::operator==(const PictureData& other) const
{
	return this->getDesc() == other.getDesc() && this->getLikes() == other.getLikes();
}

Comment& PictureData::operator[](const int& index) const
{
	return *this->coms[index];
}

Comment PictureData::operator[](const int& index)
{
	return *this -> coms[index];
}

const std::string PictureData::getDesc() const
{
	return this->desc;
}

unsigned PictureData::getLikes() const
{
	return this->likes;
}

unsigned PictureData::getComsCount() const
{
	return this->comsCount;
}

void PictureData::setDesc(const char* desc)
{
	this->desc = desc;
}

void PictureData::setLikes(const unsigned& likes)
{
	this->likes = likes;
}

void PictureData::setComsCount(const unsigned& comscount)
{
	this->comsCount = comscount;
}

void PictureData::print() const
{
	std::cout << "The picture's description is " << this->getDesc() << " and has " << this->getLikes() << " likes and " << this->getComsCount() << " comments" << std::endl;
	for (int i = 0; i < this->getComsCount(); ++i) {
		this->coms[i]->print();
	}
}

void PictureData::read()
{
	char desc[descMaxSize];
	std::cout << "Enter the description for the picture: ";
	if (std::cin.peek() == '\n') std::cin.ignore();
	std::cin.getline(desc, descMaxSize, '\n');
	bool failed = std::cin.fail();
	if (failed) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	this->setDesc(desc);

	unsigned likes = 0;
	std::cout << "Enter the number of likes: ";
	std::cin >> likes;
	this->setLikes(likes);
}

std::ostream& operator<<(std::ostream& os, const PictureData& pic)
{
	os << pic.getDesc() << "|" << pic.getLikes() << " " << pic.getComsCount() << std::endl;
	for (int i = 0; i < pic.coms.size(); ++i) {
		os << pic[i];
	}
	
	return os;
}

std::istream& operator>>(std::istream& is, PictureData& pic)
{
	char desc[descMaxSize];
	if (is.peek() == '\n') is.ignore();
	is.getline(desc,descMaxSize, '|');
	pic.setDesc(desc);

	is >> pic.likes >> pic.comsCount;
	for (int i = 0; i < pic.comsCount; ++i) {
		Comment temp;
		is >> temp;
		pic.coms.push_back(new Comment(temp));
	}

	return is;
}
