#include "ImprovedBag.h"

using namespace std;

int main() {

	ImprovedBag<int> bag;

	bag.add(0);
	bag.add(2);
	bag.add(4);
	bag.add(20);
	bag.add(15);

	bag.insert(10000, 2);

	for (int i = 0; i < 6; ++i) {
		cout << bag[i] << " ";
	}

	return 0;

}