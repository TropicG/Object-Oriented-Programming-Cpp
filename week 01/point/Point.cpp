#include "Point.h"
void Point::read()
{
	std::cout << "Enter the x coordinate: ";
	std::cin >> x;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(32, '\n');
		std::cout << "Invalid argument, try again: ";
		std::cin >> x;
	}

	std::cout << "Enter the y coordinates: ";
	std::cin >> y;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Invalid argument, try again: ";
		std::cin >> y;
	}
}
void Point::print()
{
	std::cout << "(" << x << "," << y << ")" << std::endl;
}

void Point::distanceToCenter()
{
	std::cout << "The distance to (0,0) is: " << sqrt(x * x + y * y) << std::endl;;
}

void Point::distanceToOther()
{
	Point point;
	point.read();

	std::cout << "The distance to (0,0) is: " << sqrt(pow(x - point.x, 2) + pow(y - point.y, 2)) << std::endl;
}
