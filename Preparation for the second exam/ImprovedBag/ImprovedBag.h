#ifndef IMPROVED_BAG
#define IMPROVED_BAG
#include <string>

#include "Bag.h"

template<typename T>
class ImprovedBag : public Bag<T> {
private:
	std::string brand;

public:
	ImprovedBag();
	ImprovedBag(const std::string& brand, const int& cap);
	ImprovedBag(const ImprovedBag<T>& other);
	ImprovedBag<T>& operator=(const ImprovedBag<T>& other);
	~ImprovedBag();

	void insert(const T& x, const int& index);
};

template<typename T>
inline ImprovedBag<T>::ImprovedBag() : Bag<T>(), brand("none")
{
}

template<typename T>
inline ImprovedBag<T>::ImprovedBag(const std::string& brand, const int& cap) : 
	Bag<T>(cap), brand(brand)
{
}

template<typename T>
inline ImprovedBag<T>::ImprovedBag(const ImprovedBag<T>& other) :
	Bag<T>(other), brand(other.brand)
{
}

template<typename T>
inline ImprovedBag<T>& ImprovedBag<T>::operator=(const ImprovedBag<T>& other)
{
	if (this != &other) {

		this->brand = other.brand;
		Bag<T>::operator=(other);
	}

	return *this;
}

template<typename T>
inline ImprovedBag<T>::~ImprovedBag()
{
}

template<typename T>
inline void ImprovedBag<T>::insert(const T& x, const int& index)
{
	if (this->size == this->cap) {
		this->resize();
	}

	if (index > this->size) {
		this->add(x);
		return;
	}

	this->size++;
	for (int i = this->size - 1; i > index; --i) {
		this->stuff[i] = this->stuff[i - 1];
	}
	this->stuff[index] = x;
}
#endif