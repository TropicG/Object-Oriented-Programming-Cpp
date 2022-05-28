#include "Triangle.h"

bool Triangle::valid()
{
	if ((a + b > c) || (a + c < b) || (b + c > a)) {
		return false;
	}
	return true;
}

void Triangle::input()
{
	std::cout << "Enter the a side: ";
	std::cin >> a;

	std::cout << "Enter the b side: ";
	std::cin >> b;

	std::cout << "Enter the c side: ";
	std::cin >> c;

	while (!valid()) {
		std::cout << "Invalid argument for the triangle, try again: ";

		std::cout << "Enter the a side: ";
		std::cin >> a;

		std::cout << "Enter the b side: ";
		std::cin >> b;

		std::cout << "Enter the c side: ";
		std::cin >> c;
	}
}

void Triangle::output(){
	std::cout << "The a side is: " << a << std::endl;
	std::cout << "The b side is: " << b << std::endl;
	std::cout << "The c side is: " << c << std::endl;
	std::cout << "The perimeter is: " << per() << std::endl;
	std::cout << "The area is: " << area() << std::endl;
}

int Triangle::per(){
	return a+b+c;
}

double Triangle::area() {
	return sqrt(per() * (per() - a) * (per() - b) * (per() - c));
}
