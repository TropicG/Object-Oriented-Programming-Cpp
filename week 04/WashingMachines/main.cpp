#include "WashingMachine.h"
using namespace std;

void inputSize(unsigned& size) {
	cout << "Enter the number of washing machines: ";
	cin >> size;
	while (cin.fail() || size == 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid argument, try again: ";
		std::cin >> size;
	}
}

void inputWash(WashingMachine* wash, const int& size) {

	cout << "Input the washing machines: " << endl;
	for (int i = 0; i < size; ++i) {
		cin >> wash[i];
	}
}

int getBest(const WashingMachine* wash, const int& size) {

	int best = 0;
	for (int i = 1; i < size; ++i) {
		if (wash[best] < wash[i]) {
			best = i;
		}
	}

	return best;
}

int main() {

	unsigned size = 0;
	inputSize(size);

	WashingMachine* wash = new (nothrow) WashingMachine[size];
	inputWash(wash, size);

	std::cout << "The best washing machine is: ";
	std::cout << wash[getBest(wash,size)];

	return 0;
}