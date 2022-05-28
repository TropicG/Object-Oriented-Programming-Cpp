#ifndef BAG_H
#define BAG_H

const int BY_TWO = 2;
const int STARTING_CAP = 128;

#include <iostream>

template<typename T>
class Bag {
protected:
	T* stuff = nullptr;
	int size = 0;
	int cap = 0;

protected:
	void aloc(const int& cap);
	void del();

	void resize();

public:
	Bag();
	Bag(const int& cap);
	Bag(const Bag<T>& other);
	Bag<T>& operator=(const Bag<T>& other);
	~Bag();

	void add(const T& elem);
	T get();

	T operator[](const int& index) const;

	Bag<T> operator+(const Bag<T>& other) const;

	bool operator==(const Bag<T> other) const;

	bool empty() const;
};


template<typename T>
inline void Bag<T>::aloc(const int& cap)
{
	this->stuff = new (std::nothrow) T[cap];
}

template<typename T>
inline void Bag<T>::del()
{
	delete[] this->stuff;
}

template<typename T>
inline void Bag<T>::resize()
{
	T* helper = new (std::nothrow) T[this->cap * BY_TWO];

	if (!helper) {
		delete[] helper;
		std::cout << "Failed memory allocation";
		return;
	}

	for (int i = 0; i < this->size; ++i) {
		helper[i] = this->stuff[i];
	}

	this->del();

	this->stuff = helper;

	this->cap = this->cap * BY_TWO;
}

template<typename T>
inline Bag<T>::Bag() : cap(STARTING_CAP), size(0)
{
	this->del();
	this->aloc(STARTING_CAP);

	if (!this->stuff) {
		this->del();
		std::cout << "Failed memory allocation, please try again \n";
		return;
	}
}

template<typename T>
inline Bag<T>::Bag(const int& cap) : cap(cap), size(0)
{
	this->del();
	this->aloc(cap);

	if (!this->stuff) {
		this->del();
		std::cout << "Failed memory allocation, please try again \n";
		return;
	}
}

template<typename T>
inline Bag<T>::Bag(const Bag<T>& other)
{
	this->del();

	this->aloc(other.cap);

	if (!this->stuff) {
		this->del();
		std::cout << "Failed memory allocation, please try again \n";
		return;
	}

	this->cap = other.cap;
	this->size = other.size;

	for (int i = 0; i < this->size; ++i) {
		this->stuff[i] = other[i];
	}
}

template<typename T>
inline Bag<T>& Bag<T>::operator=(const Bag<T>& other)
{
	if (this != &other) {

		this->del();
		this->aloc(other.cap);

		this->size = other.size;
		this->cap = other.cap;

		for (int i = 0; i < this->size; i++) {

			this->stuff[i] = other[i];
		}
	}

	return *this;
}

template<typename T>
inline Bag<T>::~Bag()
{
	this->del();
}

template<typename T>
inline void Bag<T>::add(const T& elem)
{
	if (this->size == this->cap) {
		this->resize();
	}

	this->stuff[this->size++] = elem;
}

template<typename T>
inline T Bag<T>::get()
{
	if (this->empty()) {
		std::cout << "Empty bag";
		return (T)0;
	}

	T temp = this->stuff[this->size-1];

	this->size--;

	return temp;
}

template<typename T>
inline T Bag<T>::operator[](const int& index) const
{
	return this->stuff[index];
}

template<typename T>
inline Bag<T> Bag<T>::operator+(const Bag<T>& other) const
{
	Bag<T> temp(this->cap + other.cap);

	for (int i = 0; i < this->size; ++i) {
		temp.add(this->stuff[i]);
	}

	for (int i = 0; i < other.size; ++i) {
		temp.add(other[i]);
	}

	return temp;
}

template<typename T>
inline bool Bag<T>::operator==(const Bag<T> other) const
{
	if (this->size != other.size) {
		return false;
	}

	for (int i = 0; i < this->size; ++i) {
		if (this->stuff[i] != other[i]) {
			return false;
		}
	}

	return true;
}

template<typename T>
inline bool Bag<T>::empty() const
{
	return this->size == 0;
}
#endif