#include "Backpack.h"
#include "Inputs.h"

int main() {

	double maxVol = 0, maxWei = 0;
	inputVol(maxVol); inputWei(maxWei);
	cout << endl;

	Backpack back(maxVol, maxWei);

	printMenu();

	while (true) {

		try {

			short option = 0;
			inputOption(option);

			if (option == 1) {

				Item i;
				cin >> i;
				back.add(i);
				cout << "Item added succsesfully" << endl;
			}
			else if (option == 2) {
				
				int index = 0;
				inputIndex(index);
				cout << back[index];
				cout << endl;
			}
			else if (option == 3) {

				cout << "The size is " << back.getSize() << endl;
				cout << endl;
			}
			else if (option == 4) {

				cout << "There is " << back.leftVolume() << " free volume" << endl;
				cout << endl;
			}
			else if (option == 5) {

				cout << "There is " << back.leftWeight() << " free weight" << endl;
				cout << endl;
			}
			else {
				break;
			}
		}
		catch (VolumeOverflow& vo) {
			cout << vo.what() << endl;
		}
		catch (WeightOverflow& wo) {
			cout << wo.what() << endl;
		}
		catch (out_of_range& ofr) {
			cout << ofr.what() << endl;
		}
	}

	return 0;
}