#include "Garage.h"
#include <iostream>

using namespace std;

int main() {

	Garage gar(20);

	Car car1("mark", 190);
	Car car2("mark", 220);
	Car car3("mark", 212);

	Van van1("mark", 131);
	Van van2("mark", 142);
	Van van3("mark", 154);

	Truck truck1("mark", 90);
	Truck truck2("mark", 100);
	Truck truck3("mark", 120);
	
	gar.add(&car1);
	gar.add(&car2);
	gar.add(&car3);


	gar.add(&van1);
	gar.add(&van2);
	gar.add(&van3);

	gar.add(&truck1);
	gar.add(&truck2);
	gar.add(&truck3);

	std::cout << gar.getSuccsessfullOrderCount(150,75,50,1);

	return 0;
}